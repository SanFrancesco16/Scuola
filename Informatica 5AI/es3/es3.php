<html>
    <head>
        <title>iohoc</title>
    </head>
    <body>
        <?php
            echo "--------------------<br><br>";
            foreach(file("utenti.txt") as $righa) {
                $p=explode("-",$righa);
                $primacolonna=$p[0];
                $secondacolonna=$p[1];

                echo "username: $primacolonna <br><br> password: $secondacolonna<br><br>--------------------<br><br>";
            }
        ?>
    </body>
</html>