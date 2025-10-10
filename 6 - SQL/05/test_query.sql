CREATE TABLE if not exists Users (

    email VARCHAR(255) NOT NULL,
    name VARCHAR(255) NOT NULL,
    second_name VARCHAR(255) NOT NULL,
    PRIMARY KEY (email)
);

CREATE TABLE if not exists PhoneNumbers (
    email VARCHAR(255) NOT NULL,
    phone_number VARCHAR(255) NOT NULL,
    FOREIGN KEY (email) REFERENCES Users (email),
    PRIMARY KEY (phone_number, email)
);

INSERT INTO Users (email, name, second_name)
VALUES ('ivanov@mail.com', 'Иван', 'Иванов');

INSERT INTO PhoneNumbers (email, phone_number)
VALUES ('ivanov@mail.com', '+79990001111');

INSERT INTO PhoneNumbers (email, phone_number)
VALUES ('ivanov@mail.com', '+79990002222');

DROP TABLE phonenumbers, Users;
