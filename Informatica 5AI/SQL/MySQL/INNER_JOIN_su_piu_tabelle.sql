CREATE DATABASE nazioni_e_continenti;
CREATE TABLE nazioni(
    nome varchar(100),
    codContinente varchar(30)
);
CREATE TABLE continenti(
    idContinente varchar(100),
    nome varchar(100)
);
SELECT *
FROM nazioni INNER JOIN continenti
ON nazioni.codContinente = continenti.idContinente;
