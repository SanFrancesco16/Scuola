<html>
	<head>
		<title>titolo</title>
	</head>
	<body>
		<?php
			$usernamecheck="ciccio";
			$passwordcheck="ciao123";
			if($_POST["username_t"]==$usernamecheck AND $_POST["pass"]==$passwordcheck){
				echo "<h2><center>ben fatto!</center></h2>";
				echo "benvenuto<br>";
				echo "il tuo username: ".$usernamecheck;
				echo "<br>la tua password: ".$passwordcheck;
			}else{
				echo "username e/o password errata/i";
			}
		?>
	</body>
</html>