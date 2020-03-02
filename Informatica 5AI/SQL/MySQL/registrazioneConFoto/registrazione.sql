CREATE database login;
CREATE TABLE registazione (
  id int(32) primary key auto_increment,
  nome text(32),
  cognome text(32),
  email text(255) UNIQUE,
  username text(64) UNIQUE,
  password text(1024),
  file blob
);