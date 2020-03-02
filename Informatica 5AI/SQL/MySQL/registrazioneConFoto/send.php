<?php
    
    $servername = "localhost";
    $username = "root";
    $password = "";
    $dbname = "login";


    $data = fopen ($_FILES['file']['tmp_name'], 'rb');
    $size=filesize ($_FILES['file']['tmp_name']);
    $contents= fread ($data, $size);
    fclose ($data);
    

    // Create connection
    $conn = new mysqli($servername, $username, $password, $dbname);
    // Check connection
    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }

    $stmt = $conn->prepare("INSERT INTO registazione (nome, cognome, email, username, password, file)
    VALUES (?, ?, ?, ?, ?, ?)");
    $stmt->bind_param("ssssss", $_POST["nome"], $_POST["cognome"], $_POST["email"], $_POST["user"], password_hash($_POST["pass"], PASSWORD_DEFAULT), $contents);

    if ($stmt->execute() === TRUE) {
        $output = '<div class="alert alert-success" role="alert"><h4 class="card-title mt-3 text-center">Account creato con successo!</h4></div>';
    } else {
        $output = '<div class="alert alert-danger" role="alert"><h4 class="card-title mt-3 text-center">Account non creato!</h4></div><br><hr><br>Error: ' . $sql . "<br>" . $stmt->error;
    }

    
    $stmt->close();
    $conn->close();   
?>


<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">

    <link href="//maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css" rel="stylesheet" id="bootstrap-css">
    <script src="//maxcdn.bootstrapcdn.com/bootstrap/4.0.0/js/bootstrap.min.js"></script>
    <script src="//cdnjs.cloudflare.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>

    <link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.0.8/css/all.css">

    <link rel="stylesheet" href="main.css">


    <title>Login</title>
</head>
<body>
    <br>
    <div class="container">
        <div class="card bg-light">
        <article class="card-body mx-auto" style="max-width: 400px;">
            <?php
                echo $output;
            ?>            
        </article>
        </div> <!-- card.// -->

    </div> 
    <!--container end.//-->

<br><br>

</body>
</html>