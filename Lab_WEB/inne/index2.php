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
        <div id="formularz">
          <form action="obliczenia.php" method="POST">
            <label for="liczba">Liczba:</label>
            <input type="text" name="liczba" size=5 maxsize=5 /><br />
            <input type="submit" name="oblicz" id="przycisk" value="Oblicz" />
          </form>
        </div>
      </section>
    </main>
    <footer>
      <h4 class="footer-tekst">Copyright &copy; Łukasz Gotówko</h4>
    </footer>
  </div>
</body>
</html>