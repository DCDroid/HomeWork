SELECT title, duration
FROM track
ORDER BY duration DESC
LIMIT 1;

SELECT title
FROM track
WHERE duration >= 3.5;

SELECT title
FROM compilation
WHERE release BETWEEN '2018-01-01' and '2020-12-31';

SELECT name
FROM perfomer
WHERE (LENGTH(name) - LENGTH(REPLACE(name, ' ', ''))) = 0

SELECT title
FROM track
WHERE title LIKE '%My%' or title LIKE '%мой%';

-- 

SELECT g.name, COUNT(p.perfomer_id) FROM genre g
JOIN perfomer_genre p ON g.id = p.genre_id
GROUP BY g.name

SELECT COUNT(t.title) FROM track t
JOIN album a ON t.album_id = a.id
WHERE a.release BETWEEN '2019-01-01' and '2020-12-31'

SELECT a.title, AVG(t.duration) FROM track t
JOIN album a ON t.album_id = a.id
GROUP BY a.title;

SELECT DISTINCT p.name
FROM perfomer p
WHERE NOT EXISTS (
    SELECT 1
    FROM perfomer_album p_a
    JOIN album a ON p_a.album_id = a.id
    WHERE p_a.perfomer_id = p.id AND a.release BETWEEN '2020-01-01' AND '2020-12-31'
);

SELECT DISTINCT c.title
FROM compilation c
JOIN compilation_track ct ON c.id = ct.compilation_id
JOIN track t ON ct.track_id = t.id
JOIN album a ON t.album_id = a.id
JOIN perfomer_album pa ON a.id = pa.album_id
JOIN perfomer p ON pa.perfomer_id = p.id
WHERE p.name = 'Bon Jovi';