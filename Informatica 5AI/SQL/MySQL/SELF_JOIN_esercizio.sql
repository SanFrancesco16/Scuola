DROP DATABASE stdudenti_e_voti_SELF_JOIN;
CREATE DATABASE stdudenti_e_voti_SELF_JOIN;

USE stdudenti_e_voti_SELF_JOIN;

/*  il self join consente di unire una tabella a se stessa  */

CREATE TABLE Persona(
    id_persona VARCHAR(20),
    nome VARCHAR(20),
    cognome VARCHAR(20),
    id_coniuge VARCHAR(20)
);
/*  nel self join bisogna creare una nuova tabella di quella che ci interessa, quindi dato 
che in questo caso ci interessa la tabella "Persona" bisogna appunto reare una copia di sta tabella 
per poter confrontare i dati  */
SELECT *
FROM Persona_T1 AS PT1, Persona_T2 AS PT2
WHERE PT1.id_persona=PT2.id_coniuge;