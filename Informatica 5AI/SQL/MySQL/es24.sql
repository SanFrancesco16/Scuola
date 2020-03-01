DROP DATABASE db_circolo; 
CREATE DATABASE db_circolo;
USE db_circolo;

CREATE TABLE cacciatore(
    codice INT(2),
    nome VARCHAR(20)
);
CREATE TABLE pescatore(
    codice INT(2),
    nome VARCHAR(20)
);
CREATE TABLE scalatore(
    codice INT(2),
    nome VARCHAR(20)
);

INSERT INTO cacciatore(codice,nome)
VALUES (35,'ROSSI');
INSERT INTO cacciatore(codice,nome)
VALUES (27,'NERI');
INSERT INTO cacciatore(codice,nome)
VALUES (12,'BIANCHI');
INSERT INTO cacciatore(codice,nome)
VALUES (2,'BISCARDI');

INSERT INTO pescatore(codice,nome)
VALUES (4,'ROSSI');
INSERT INTO pescatore(codice,nome)
VALUES (77,'MANCINI');
INSERT INTO pescatore(codice,nome)
VALUES (49,'CRUCIANI');
INSERT INTO pescatore(codice,nome)
VALUES (11,'MARCA');

INSERT INTO scalatore(codice,nome)
VALUES (27,'NERI');
INSERT INTO scalatore(codice,nome)
VALUES (11,'MARCA');
INSERT INTO scalatore(codice,nome)
VALUES (1,'MICHELI');
INSERT INTO scalatore(codice,nome)
VALUES (2,'BISCARDI');


/*
11)SCRIVERE UNA QUERY PER VISUALIZZARE TUTTI I NOMINATIVI ISRITTI AL CIRCOLO
*/




/*
12)SCRIVERE UNA QUERY PER VIUSALIZZARE I CACCIATORI CHE NON SIANO ANCHE SCALATORI       
*/

SELECT *
FROM cacciatore LEFT JOIN scalatore
ON cacciatore.codice = scalatore.codice
WHERE scalatore.codice IS NULL;

/*
13)SCRIVERE UNA QUERY PER VISUALIZZARE GLI SCALATORI CHE NON SIANO ANCHE CACCIATORI     
*/

SELECT *
FROM scalatore LEFT JOIN cacciatore
ON scalatore.codice=cacciatore.codice 
WHERE cacciatore.codice IS NULL;


/*
14)SCRIVERE UNA QUERY PER VISUALIZZARE I pecatori CHE SIANO ANCHE CACCIATORI
*/

/*la query non mostra alcun risultato perchè nella tabella pescatori e cacciatori non ci sono utenti con stesso codice
infatti si nota che nella prima righa di cacciatori c'è ROSSI con codice 35 e in pescatori c'è ROSSI 
con codice 4, si ipotizza così che siano omonimi*/
SELECT *
FROM pescatore AS S INNER JOIN cacciatore AS C
ON S.codice=C.codice;


/*
15)SE DOVESSIMO SCRIVERE UNA QUERY PER VISUALIZZARE I CACCIATORI CHE SIANO ANCHE PESCATORI POTREMMO 
UTILIZZARE LA SOLUZIONE DELL'ESERCIZIO N°14? 
*/

/*  Si ma si dovrebbero invertire l'ordine delle tabelle quindi fare la seguente query:  */
SELECT *
FROM cacciatore AS C INNER JOIN pescatore AS P
ON C.codice=P.codice;       /*  anche in questo caso non visualizza nessun risultato perchè non c'è nessun
                                campo che abbia codice uguale  */


/*
16)SCRIVERE UNA QUERY PER VISUALIZZARE TUTTI I NOMINATIVI ISCRITTI A CIRCOLO IL CUI NOME 
FINISCE CON "L" E CI SIA ALMENO UNA "A"
*/

/*  in questo caso nel DB non c'è nesun nome che abbia una A al suo interno e finisca con la lettera
L, per cui non visualizza nulla a schermo */
SELECT cacciatore.nome,pescatore.nome,scalatore.nome 
FROM cacciatore,pescatore,scalatore 
WHERE cacciatore.nome LIKE "%A%L" 
OR pescatore.nome LIKE "%A%L" 
OR scalatore.nome LIKE "%A%L";


/*
SCRIVERE UNA QUERY PER VISUALIZZARE TUTTI I NOMINATIVI ISCRITTI AL CIRCOLO IL CUI NOME FINISCE CON "L" O CI SIA ALMENO 
UNA "A"
*/

SELECT C.nome,P.nome,S.nome
FROM cacciatore AS C pescatore AS P,scalatore AS S
WHERE C.nome LIKE "%L" OR C.nome LIKE "%A%"
OR P.nome LIKE "%L" OR P.nome LIKE "%A%"
OR S.nome LIKE "%L" OR S.nome LIKE "%A%";