CREATE DATABASE stdudenti_e_voti_RIGHT_JOIN;
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
/*  ottenere i risultati degli studenti che non hanno voto(quindi non fatt l'esame)  */
SELECT * 
FROM studenti AS S RIGHT JOIN voti AS V   
/*  bisogna mettere la tabella studenti(S) e la tablla voto(V) in oridine come
scritto nella "join", quindi in questo caso prima va quella a destra voti(V)
e poi quella a sinistra dell'operatore "JOIN", dunque la tabella studenti(S).
il risultato nella "ON" sarà quindi la seguente  */
ON V.matricola=S.matricola
WHERE voto=NULL; 