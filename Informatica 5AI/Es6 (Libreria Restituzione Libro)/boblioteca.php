<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>Page Title</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" type="text/css" media="screen" href="main.css" />
    <script src="main.js"></script>
</head>
<body>
    <?php

        $mesi=array(31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31);
        $filedata=fopen("date.txt", "r") or die ("file non aperto");
        $scrivigiorni=fopen("giorniBiblioteca.txt", "a+");
        
        
        while (!feof($filedata)) {
            $puntatore=explode("/", fgets($filedata));
            
            if(trim($puntatore[1])!=trim($puntatore[3])){
                $cont=0;
                for ($i=trim($puntatore[1])+1; $i < trim($puntatore[3]); $i++) { 
                    $cont+=$mesi[$i-1];
                }
                $cont+=$mesi[trim($puntatore[1])-1]-trim($puntatore[0])+trim($puntatore[2]);
                echo "mesi diversi, num giorni: ".$cont."<br>";
                fwrite($scrivigiorni, "mesi diversi, num giorni: ".$cont."\n");
            }else {
                $numgiorni=trim($puntatore[2])-trim($puntatore[0]);
                echo "mesi uguali, num giorni: ".$numgiorni."<br>";
                fwrite($scrivigiorni, "mesi uguali, num giorni: ".$numgiorni."\n");
            }
        }
        fclose($filedata);
        fclose($scrivigiorni);
    ?>
</body>
</html>