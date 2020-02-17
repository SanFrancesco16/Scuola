<html>
	<head>
		<title>ricerca.php</title>
	</head>
	<body>
		<?php
			//apre la connessione al database
			$hostname="localhost";
			$username="root";
			$password="";
			
			//connessione al server SQL
			$conn=mysqli_connect($hostname,$username,$password);
			if(!$conn){
				die("errore di connessione");
			}
			
			//selezionare database
			$dbname="videoteca";
			$db=mysqli_select_db($dbname);
			$codice=$_POST["codicefilm"];
			$query="SELECT * FROM film WHERE codicefilm='$codice'";
			$risultato=mysqli_query($query);
			if(!$risultato){
				echo "errore";
				exit();
			}
			
			//recupero dati
			$riga=mysqli_fetch_array($risultato);
			if(!$riga){
				echo "codie non valido";
			}else{
				echo $riga[titolo].$riga[trama];
			}
			
			//chiusura della connesione al database
			mysqli_close($conn);
			
		?>
	</body>
</html>
