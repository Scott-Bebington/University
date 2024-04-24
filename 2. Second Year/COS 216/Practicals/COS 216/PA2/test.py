import requests

url = 'https://wheatley.cs.up.ac.za/api/'

data = {
    "studentnum": "u12345678",
    "type": "GetAllCars",
    "apikey": "a9198b68355f78830054c31a39916b7f",
    "fuzzy": True,
    "distinct": False,
    "return": [
        "make",
    ]
    # "return": "*"
}

response = requests.post(url, json=data)

if response.status_code == 200:
    for car in response.json()['data']:
        # print("id_trim: " + str(car['id_trim']))
        print("Make: " + car['make'])
        # print("Model: " + car['model'])
        # print("Generation: " + car['generation'])
        # print("Year From: " + str(car['year_from']))
        # print("Year To: " + str(car['year_to']))
        # print("Series: " + str(car['series']))
        # print("Trim: " + str(car['trim']))
        # print("Body Type: " + str(car['body_type']))
        # print("Number of seats: " + str(car['number_of_seats']))
        # print("Length mm: " + str(car['length_mm']))
        # print("Width mm: " + str(car['width_mm']))
        # print("Height mm: " + str(car['height_mm']))
        # print("Number of cylinders: " + str(car['number_of_cylinders']))
        # print("Fuel type: " + str(car['engine_type']))
        # print("Drivetrain: " + str(car['drive_wheels']))
        # print("Transmission: " + str(car['transmission']))
        # print("Top speed: " + str(car['max_speed_km_per_h']))



else:
    print("Error: ", response.status_code)
print(response.json())
