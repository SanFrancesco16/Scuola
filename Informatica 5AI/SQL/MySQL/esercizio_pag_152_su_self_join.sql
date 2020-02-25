DROP DATABASE azienta_SELF_JOIN;
CREATE DATABASE azienta_SELF_JOIN;
USE azienta_SELF_JOIN;
CREATE TABLE Dipendente(
    codice VARCHAR(20),
    cognome VARCHAR(20),
    nome VARCHAR(20),
    codice_capo VARCHAR(20)
);

INSERT INTO Dipendente(codice,cognome,nome,codice_capo)
VALUES ('1','Rossi','Mario','6');
INSERT INTO Dipendente(codice,cognome,nome,codice_capo)
VALUES ('2','Verdi','Luigi','5');
INSERT INTO Dipendente(codice,cognome,nome,codice_capo)
VALUES ('3','Bianchi','Maria','6');
INSERT INTO Dipendente(codice,cognome,nome,codice_capo)
VALUES ('4','Bruni','Clara','5');
INSERT INTO Dipendente(codice,cognome,nome,codice_capo)
VALUES ('5','Neri','Luca','4');
INSERT INTO Dipendente(codice,cognome,nome,codice_capo)
VALUES ('6','Conti','Filippo','6');

SELECT DT2.nome, DT2.cognome
FROM Dipendente AS DT1, Dipendente AS DT2
WHERE DT1.codice_capo=DT2.codice
AND DT1.cognome='Verdi';
/*
controllare se  nel caso si fosse inserita la query:
    SELECT DT2.nome, DT2.cognome
    FROM Dipendente AS DT1, Dipendente AS DT2
    WHERE DT1.codice_capo=DT2.codice
    AND DT2.cognome='Verdi';
fosse stato uguale   
*/