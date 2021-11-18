<!DOCTYPE html>
<html lang="pl" dir="ltr">
<head>
  <meta charset="utf-8">
  <title>PHP - funkcje</title>
</head>
<body>
  <?php
    if(isset($_POST['oblicz']))
      $liczba = $_POST['liczba'];
    else
      $liczba = 0;
    
    function ciagLiczbowy($ilosc) { 
        echo "Ci&#261;g fibonaci " . $ilosc . " cyfr : </br>";
          for($i=0; $i<=$ilosc; $i++) {
            $b = fibo($i);
            echo "$b ";
            
          }
        
        
        
      
      
    }
    function fibo($liczbaa){
      if($liczbaa == 0 || $liczbaa == 1){
        return $liczbaa;
      }
      return fibo($liczbaa - 2) + fibo($liczbaa - 1);
    }

    ciagLiczbowy($liczba);
    
    
  ?>
</body>
</html>