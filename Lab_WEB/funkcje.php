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
        $sql = 'INSERT INTO uzytkownicy1 (imie, nazwisko, email, user, password)
            VALUES("'.$firstName.'", "'.$lastName.'", "'.$email.'","'.$username.'", "'.$pass.'")';
        $connection = connect();
        $connection->exec($sql);
        
    }
    function getPass($user){

        
        $sql = ' SELECT password from uzytkownicy1 where user = "'.$user.'"' ;
        $connection = connect();
        $stmt = $connection->prepare($sql);
        $stmt->execute();
        $result = $stmt->setFetchMode(PDO::FETCH_ASSOC);
        $row = $stmt->fetch();
        $wynik = $row["password"];
        return $wynik;
    }
    function userCheck($user){
        $sql = ' SELECT user from uzytkownicy1';
        $connection = connect();
        $stmt = $connection->prepare($sql);
        $stmt->execute();
        $result = $stmt->setFetchMode(PDO::FETCH_ASSOC);
        while($row = $stmt->fetch()){
            if($row["user"] == $user){
                return false;
            }
        }
        return true;
    }
