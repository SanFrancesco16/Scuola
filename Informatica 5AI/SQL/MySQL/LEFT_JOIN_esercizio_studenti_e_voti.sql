CREATE DATABASE studenti_e_voti;
CREATE TABLE studenti(
    matricola VARCHAR(20),
    nome VARCHAR(20),
    cognome VARCHAR(20)
);
CREATE TABLE voti(
    matricola VARCHAR(20),
    voto VARCHAR(20),
    materia VARCHAR(20)
);
SELECT *
FROM studenti AS S LEFT JOIN voti AS V
ON S.matrcicola=V.matrcicola;