How to use: When Visiting the website, you are taken to the INdex page which has a list of all the cars on my website, you can then choose to brows through all of the different car pages such as the:
Find Car: this is a more specific car page designed to help you find your perfect car.
Brands: This page displays a list of brands given on the website.
Compare: This page allows the coustomer to compare the specifications of 2 cars of their choosing.
Login: this page allows the user to log into their account using their login details.
Sign Up: this allows a user without an account to create an account with their email address and password.
Logout: once the user is logged in they have the choice to logout of the page if they dont want to stay signed in.
(All functionality has been implimented)

Default login details:
Email:     scottbebington@gmail.com
Password:  Scott12!


Header: Header is contained in the header.php file, this is called using a "include_once" statement for each page that uses it.

Footer: My website never container a footer page and therefor i cannot include it.

Signup: The user should have Capital letters, lowercase letters, special characters and numbers in order to make it harder for hackers to use the brute force method to get your paswword.
API key: i generated an API key for each user by picking 15 random digits from all the letters (both capital and lower case) as well as the numbers.
Hashing algorithm: The first half of the hashing algorithm uses PASSWORD_ARGON2I and the second half of the hashing uses PASSWORD_ARGON2D, combining the best parts of both hashing algorithms allows for safe and secure password saving.
Validation: I use both js validation and PHP validation to check if the user does not meet the criteria for both email and password.
Password: I do believe the passwords should be made slightly longer as most people have passwords longer than 8 characters and it is very limiting.



