// Author: Scott Bebington u21546216

/**
 * To run locally
 * clear && node .mongoshrc.js
 */

const { MongoClient } = require('mongodb');
require('dotenv').config();

const username = process.env.MONGO_USERNAME;
const password = process.env.MONGO_PASSWORD;

// Connection URL and Database name
const url = 'mongodb+srv://' + username + ':' + password + '@cos301prac7.koccw.mongodb.net/?retryWrites=true&w=majority&appName=COS301Prac7';
const client = new MongoClient(url);
const dbName = 'HospitalDB';
const colName = 'Patients';

/**
 * Task 1 functions
 */

const ailmentList = [
  'Cold',
  'Flu',
  'Chickenpox',
  'Malaria',
  'Diabetes',
  'Hypertension',
  'Asthma',
  'Bronchitis',
  'Pneumonia',
  'Tuberculosis'
]

async function insertPatients(dbName, colName, patientCount) {
  try {

    await client.connect();
    console.log('Connected successfully to MongoDB server');


    const db = client.db(dbName);

    const collection = db.collection(colName);

    const randomAilment = () => {
      return ailmentList[Math.floor(Math.random() * ailmentList.length)];
    }

    const randomAge = () => {
      return Math.floor(Math.random() * 100);
    }

    const randomName = () => {
      var patientName = "Patient_";
      const characters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789';
      for (let i = 0; i < 10; i++) {
        patientName += characters.charAt(Math.floor(Math.random() * characters.length));
      }
      return patientName;
    }

    const randomDoctor = () => {
      const doctorList = ['Dr. Green', 'Dr. Blue', 'Dr. Red', 'Dr. Yellow', 'Dr. Purple'];
      return doctorList[Math.floor(Math.random() * doctorList.length)];
    }

    for (let i = 0; i < patientCount; i++) {
      const insertResult = await collection.insertOne({
        name: randomName(),
        age: randomAge(),
        ailment: randomAilment(),
        doctor: randomDoctor(),
        admitted: true,
        appointments: [
          {
            date: "2024-09-01",
            reason: "Cold checkup"
          },
          {
            date: "2024-09-15",
            reason: "Follow-up"
          }
        ]
      });
      console.log('Inserted document:', insertResult);
    }

  } catch (err) {
    console.log("Error inserting the patients");

  } finally {

    await client.close();
  }
}

async function findAdmittedPatients(dbName, colName) {
  try {

    await client.connect();
    console.log('Connected successfully to MongoDB server');


    const db = client.db(dbName);


    const collection = db.collection(colName);


    const findResult = await collection.find({ admitted: true }).toArray();
    console.log('Found documents:', findResult);

  } catch (err) {
    console.log("Error finding the admitted patients");
  } finally {

    await client.close();
  }
}

async function updatePatientAdmission(dbName, colName, patientName, status) {
  try {

    await client.connect();
    console.log('Connected successfully to MongoDB server');


    const db = client.db(dbName);


    const collection = db.collection(colName);


    const updateResult = await collection.updateOne(
      { name: patientName },
      { $set: { admitted: status } }
    );
    console.log('Updated document:', updateResult);

  } catch (err) {
    console.log("Error updating the patient record");
  } finally {

    await client.close();
  }
}

async function removeDischargedPatients(dbName, colName) {
  try {

    await client.connect();
    console.log('Connected successfully to MongoDB server');


    const db = client.db(dbName);


    const collection = db.collection(colName);

    const removeResult = await collection.deleteMany({ admitted: false });
    console.log('Removed documents:', removeResult);

  } catch (err) {
    console.log("Error removing the discharged patients");
  } finally {

    await client.close();
  }
}

// insertPatients(dbName, colName, 10); 
// findAdmittedPatients(dbName, colName);
// updatePatientAdmission(dbName, colName, 'Patient_JAB7A2AqGX', false);
// removeDischargedPatients(dbName, colName);

/**
 * Task 2 functions
 */

async function doctorStats(dbName, colName) {
  try {

    await client.connect();
    console.log('Connected successfully to MongoDB server');


    const db = client.db(dbName);


    const collection = db.collection(colName);

    // Use aggregation pipeline to get doctor stats
    const doctorList = await collection.aggregate([
      {
        $group: {
          _id: "$doctor",
          patientCount: { $sum: 1 }
        }
      },
      {
        $sort: { _id: 1 }
      }
    ]).toArray();

    console.log('Doctor stats:', doctorList);

  } catch (err) {
    console.log("Error getting the doctor stats");
  } finally {

    await client.close();
  }
}

async function doctorPatientList(dbName, colName, doctorName) {
  try {

    await client.connect();
    console.log('Connected successfully to MongoDB server');


    const db = client.db(dbName);


    const collection = db.collection(colName);


    const findResult = await collection.find({ doctor: doctorName }).toArray();
    for (let i = 0; i < findResult.length; i++) {
      console.log('Patient:', findResult[i]['name']);
      console.log('Age:', findResult[i]['age']);
      console.log('Ailment:', findResult[i]['ailment']);
      console.log('Admitted:', findResult[i]['admitted']);
      console.log('Appointments:');
      console.log("{");
      for (let j = 0; j < findResult[i]['appointments'].length; j++) {
        console.log('\t', findResult[i]['appointments'][j]);
      }
      console.log("}\n");
    }

  } catch (err) {
    console.log("Error finding the patients for the doctor");
  } finally {

    await client.close();
  }
}

async function activeDoctorsMR(dbName, colName) {
  try {

    await client.connect();
    console.log('Connected successfully to MongoDB server');


    const db = client.db(dbName);


    const collection = db.collection(colName);

    const doctorList = await collection.aggregate([
      {
        $group: {
          _id: 0,
          name: "$doctor",
          patientCount: { $sum: 1 }
        }
      }
    ]).toArray();

    const doctorActivityCollection = db.collection('DoctorActivity');

    const results = await doctorActivityCollection.insertMany(doctorList);

  } catch (err) {
    console.log("Error getting the doctor stats");
  } finally {

    await client.close();
  }
}

async function appointmentStats(dbName, colName) {
  try {

    await client.connect();
    console.log('Connected successfully to MongoDB server');


    const db = client.db(dbName);


    const collection = db.collection(colName);

    const formattedAppointments = await collection.aggregate([
      {
        $unwind: "$appointments"
      },
      {
        $project: {
          _id: 0,
          doctor: "$doctor",
          patient: "$name",
          date: "$appointments.date"
        }
      }
    ]).toArray();

    const newCollection = db.collection("Appointments");
    await newCollection.insertMany(formattedAppointments);

    console.log(`Inserted appointments into "Appointments" collection`);
  } catch (err) {
    console.log("Error getting the appointment stats:", err);
  } finally {

    await client.close();
  }
}

// doctorStats(dbName, colName);
// doctorPatientList(dbName, colName, 'Dr. Red');
activeDoctorsMR(dbName, colName);
// appointmentStats(dbName, colName);




