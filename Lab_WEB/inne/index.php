<!DOCTYPE html>
<html lang="pl" dir="ltr">
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1" />
  <title>TSW - laboratorium 4</title>
  <link rel="stylesheet" type="text/css" href="style.css" />
</head>
<body>
  <div id="container">
    <header>
      <h1 class="header-tekst">Wprowadzenie do języka PHP</h1>
    </header>
    <main class="page">
      <noscript>
        <p>Twoja przeglądarka nie obsługuje JavaScript. Upewnij się, że w przeglądarce masz włączoną obsługę JavaScript.</p>
      </noscript>
      <nav class="navigation">
        <h3 class="navigation-name">MENU</h3>
        <div class="menu">
          <ul>
            <li><a href="index.html" class="active">O przedmiocie</a></li>
            <li><a href="prowadzacy.html">Prowadzący</a></li>
            <li><a href="plan.html">Plan zajęć</a></li>
            <li><a href="godziny.html">Godziny konsultacji</a></li>
            <li><a href="rejestracja.html">Rejestracja studenta</a></li>
          </ul>
        </div>
      </nav>
      <section class="main-content">
        <p id="strona-glowna">
          Ciągi liczbowe 
        </p>
        <?php

        class czcio{
          public $czcionka;
          public $kolor;
          public $grub;
          function __construct($czcionka, $kolor, $grub){
            $this->czcionka = $czcionka;
            $this->kolor = $kolor;
            $this->grub = $grub;
            $this->Wypisz();

          }
          function Wypisz(){
            if($this->grub == 1){
            echo "<b><p style='color:".$this->kolor.";font-size:".$this->czcionka."px'>Ten text ma ".$this->czcionka."px i jest ".$this->kolor."</p><b>";
            }
            else{
              echo "<p style='color:".$this->kolor.";font-size:".$this->czcionka."px'>Ten text ma ".$this->czcionka."px i jest ".$this->kolor."</p>";
            }
          }
        }
        $tekst1 = new czcio(10,"red", 0);
        $tekst2 = new czcio(40,"blue", 0);
        $tekst3 = new czcio(20,"yellow", 1);

        ?>
      </section>
    </main>
    <footer>
      <h4 class="footer-tekst">Copyright &copy; Łukasz Gotówko</h4>
    </footer>
  </div>
</body>
</html>