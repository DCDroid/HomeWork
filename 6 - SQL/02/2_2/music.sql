CREATE TABLE if not exists Perfomer (
    id INT NOT NULL PRIMARY KEY,
    name VARCHAR(255) NOT NULL
);

CREATE TABLE if not exists Genre (
    id INT NOT NULL PRIMARY KEY,
    name VARCHAR(255) NOT NULL
);

CREATE TABLE if not exists Album (
    id INT NOT NULL PRIMARY KEY,
    title VARCHAR(255) NOT NULL,
    release date
);

CREATE TABLE if not exists Compilation (
    id INT NOT NULL PRIMARY KEY,
    title VARCHAR(255) NOT NULL,
    release date
);

CREATE TABLE if not exists Track (
    id INT PRIMARY key references album(id),
    title VARCHAR(255) NOT NULL,
    duration INT,
    album_id INT NOT NULL
);


CREATE table if not exists Perfomer_Genre (
    perfomer_id INT NOT null REFERENCES Perfomer(id),
    genre_id INT NOT null REFERENCES Genre(id),
    constraint pk1 primary key (perfomer_id, genre_id)
);

CREATE table if not exists perfomer_Album (
    perfomer_id INT NOT NULL,
    album_id INT NOT NULL,
    PRIMARY KEY (perfomer_id, album_id),
    FOREIGN KEY (perfomer_id) REFERENCES Perfomer(id),
    FOREIGN KEY (album_id) REFERENCES Album(id)
);

CREATE TABLE if not exists Compilation_Track (
    compilation_id INT NOT NULL,
    track_id INT NOT NULL,
    PRIMARY KEY (compilation_id, track_id),
    FOREIGN KEY (compilation_id) REFERENCES Compilation(id),
    FOREIGN KEY (track_id) REFERENCES Track(id)
);
