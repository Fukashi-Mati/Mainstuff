<?php include('funkcje.php');

session_start();
if(isset($_POST['logowanie'])){
    $name = $_POST['uName'];
    $pass = $_POST['pass'];
    $name = trim($name, ";");
    $password = md5($pass);
    $passsdb = getPass($name);
    if(!userCheck($name)){
      if($password == $passsdb){
          $_SESSION['username'] = $name;
          header("Location: /Lab_WEB/index.php");
      }
      else{
        echo("Bledne haslo");
      }
    }
    else{
      echo("Nie znaleziono uzytkownika");
    }
}


?> 
<!DOCTYPE html>
<html lang="pl" dir="ltr">
<head>
  <meta charset="utf-8" />
  <title>PHP - MySQL</title>
  <link rel="stylesheet" type="text/css" href="style2.css">
</head>
<body>
<div id="formularz">
    <form action="login.php" method="POST">
      <ul class="flex">
        <li class="form-group">
          <label for="uName">Nazwa u&#380;ytkownika:</label>
          <input type="text" name="uName" size=20 maxsize=30 required /><br />
        </li>
        <li class="form-group">
          <label for="pass">Has&#322;o:</label>
          <input type="password" name="pass" size=20 maxsize=50 required /><br />
        </li>
        <li class="form-group">
          <button type="submit" name="logowanie" id="przycisk" >Zaloguj</button>
        </li>
        <li class="form-group">
          <p>
            Nie masz konta?
            <a href="register.php">Rejestracja</a>
</body>
</html>
