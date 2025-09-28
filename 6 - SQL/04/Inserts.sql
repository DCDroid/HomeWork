INSERT INTO perfomer(id, name)
VALUES(1, 'Bon Jovi');
INSERT INTO perfomer(id, name)
VALUES(2, 'Roxette');
INSERT INTO perfomer(id, name)
VALUES(3, 'Radiohead');

INSERT INTO genre(id, name)
VALUES(1, 'Rock');
INSERT INTO genre(id, name)
VALUES(2, 'Pop');
INSERT INTO genre(id, name)
VALUES(3, 'R&B');

INSERT INTO perfomer_genre(perfomer_id, genre_id)
VALUES(1, 1);
INSERT INTO perfomer_genre(perfomer_id, genre_id)
VALUES(1, 2);
INSERT INTO perfomer_genre(perfomer_id, genre_id)
VALUES(2, 1);
INSERT INTO perfomer_genre(perfomer_id, genre_id)
VALUES(3, 3);

INSERT INTO perfomer_album(perfomer_id, album_id)
VALUES(1, 1);
INSERT INTO perfomer_album(perfomer_id, album_id)
VALUES(1, 2);
INSERT INTO perfomer_album(perfomer_id, album_id)
VALUES(2, 2);
INSERT INTO perfomer_album(perfomer_id, album_id)
VALUES(3, 3);

INSERT INTO compilation(id, title, release)
VALUES(1, 'Compilation A', '2018-01-14');
INSERT INTO compilation(id, title, release)
VALUES(2, 'Compilation B', '2022-01-14');
INSERT INTO compilation(id, title, release)
VALUES(3, 'Compilation C', '2024-01-14');

INSERT INTO compilation_track(compilation_id, track_id)
VALUES(1, 1);
INSERT INTO compilation_track(compilation_id, track_id)
VALUES(1, 2);
INSERT INTO compilation_track(compilation_id, track_id)
VALUES(1, 3);
INSERT INTO compilation_track(compilation_id, track_id)
VALUES(2, 4);
INSERT INTO compilation_track(compilation_id, track_id)
VALUES(2, 5);
INSERT INTO compilation_track(compilation_id, track_id)
VALUES(2, 6);
INSERT INTO compilation_track(compilation_id, track_id)
VALUES(3, 1);
INSERT INTO compilation_track(compilation_id, track_id)
VALUES(3, 6);

INSERT INTO album(id, title, release)
VALUES(1, 'Album A', '2019-01-14');
INSERT INTO album(id, title, release)
VALUES(2, 'Album B', '2020-05-04');
INSERT INTO album(id, title, release)
VALUES(3, 'Album C', '2013-03-01');

INSERT INTO track(id, title, duration, album_id)
VALUES(1, 'My Track A', 2, 1);
INSERT INTO track(id, title, duration, album_id)
VALUES(2, 'Track B', 3, 2);
INSERT INTO track(id, title, duration, album_id)
VALUES(3, 'Track C', 4, 3);
INSERT INTO track(id, title, duration, album_id)
VALUES(4, 'Track D', 2, 1);
INSERT INTO track(id, title, duration, album_id)
VALUES(5, 'Track E', 3, 2);
INSERT INTO track(id, title, duration, album_id)
VALUES(6, 'Track F', 1, 3);

