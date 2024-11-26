// Author: Scott Bebington u21546216

/**
 * To run locally
 * clear && node test.js
 */

const { MongoClient } = require('mongodb');
require('dotenv').config();

const username = process.env.MONGO_USERNAME;
const password = process.env.MONGO_PASSWORD;

// Connection URL and Database name
const url = 'mongodb+srv://' + username + ':' + password + '@university.koccw.mongodb.net/?retryWrites=true&w=majority&appName=University';
const client = new MongoClient(url);

const dbName = 'exam';
const colName = 'test';

async function test() {
    try {

        await client.connect();
        console.log('Connected successfully to MongoDB server');


        const db = client.db(dbName);

        const collection = db.collection(colName);

        const list = await collection.aggregate(
            [
                { $match: { tags: { $elemMatch: { $eq: "NoSQL" } } } },
            ],
        ).toArray();

        console.log(list)

    } catch (err) {
        console.log("Error: ", err);
    } finally {
        await client.close();
    }
}

test();