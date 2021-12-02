<?php

    $errors = array();

    function connect(){
        $dbserver = 'localhost';
        $dbuser = 'root';
        $password = '';
        $dbname = 'mydb';
        
        $connection = new PDO("mysql:host=$dbserver;dbname=$dbname", $dbuser, $password);
        $connection->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
        
        return $connection;
    }
    function addUser($firstName, $lastName, $email, $username, $password){
        $pass = md5($password);
        $sql = 'INSERT INTO uzytkownicy (imie, nazwisko, email, user, password)
            VALUES("'.$firstName.'", "'.$lastName.'", "'.$email.'","'.$username.'", "'.$pass.'")';
        $connection = connect();
        $connection->exec($sql);
        
    }
    function getPass($user){

        
        $sql = ' SELECT password from uzytkownicy where user = "'.$user.'"' 
        
    }
