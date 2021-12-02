<?php include('funkcje.php');
if(isset($_POST['rejestracja'])){
    $imie = $_POST['fName'];
    $nazw = $_POST['lName'];
    $email = $_POST['email'];
    $user = $_POST['uName'];
    $pass1 = $_POST['pass'];
    $pass2 = $_POST['rpass'];
    if($pass1 == $pass2){
      addUser($imie, $nazw, $email, $user, $pass1);
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
  <div> 
    <h2>Rejestracja</h2>
    <hr /> 
  </div>
  <div id="error">
    <?php if(count($errors) > 0) : ?>
      <?php foreach($errors as $error) : ?>
        <p><?php echo $error ?></p>
      <?php endforeach ?>
    <?php endif ?>
  </div>
  <div id="formularz">
    <form action="register.php" method="POST">
      <ul class="flex">
        <li class="form-group">
          <label for="fName">Imie:</label>
          <input type="text" name="fName" size=20 maxsize=30 required /><br />
        </li>
        <li class="form-group">
          <label for="lName">Nazwisko:</label>
          <input type="text" name="lName" size=20 maxsize=30 required /><br />
        </li>
        <li class="form-group">
          <label for="email">Email:</label>
          <input type="email" name="email" size=20 maxsize=50 required /><br />
        </li>
        <li class="form-group">
          <label for="uName">Nazwa u&#380;ytkownika:</label>
          <input type="text" name="uName" size=20 maxsize=30 required /><br />
        </li>
        <li class="form-group">
          <label for="pass">Has&#322;o:</label>
          <input type="password" name="pass" size=20 maxsize=50 required /><br />
        </li>
        <li class="form-group">
          <label for="rpass">Powt&#243;rzone has&#322;o:</label>
          <input type="password" name="rpass" size=20 maxsize=50 required /><br />
        </li>
        <li class="form-group">
          <button type="submit" name="rejestracja" id="przycisk" >Zarejestruj</button>
        </li>
        <li class="form-group">
          <p>
            Masz ju&#380; konto?
            <a href="login.php">Logowanie</a>
          </p>
        </li>
      </ul>
    </form>
  </div>
</body>
</html>