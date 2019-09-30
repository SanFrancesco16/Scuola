<html>
    <head>
        <title>title</title>
    </head>
    <body>
        <?php
            $nome=$_POST["t1"];
            if($nome=="pippo"){
                echo "Bentornato!";
            }elseif($nome=="pluto"){
                echo "Benvenuto!";
            }
        ?>
    </body>
</html>