import matplotlib.pyplot as plt
import numpy as np

#   Połączenie z bazą danych
def connect_db():
    import psycopg2
    conn = psycopg2.connect("dbname=Python user=postgres password=admin")
    return conn
#   Pobranie danych z bazy danych
def download_data(db_connection):
    cur = db_connection.cursor()
    sql = "select temperatura, class from odczyty"
    cur.execute(sql)
    dane = cur.fetchall()
    cur.close()
    return dane
#   Przygotowanie danych w celu użycie ich do nauczenia sztucznej inteligencji
def prepare_data(dane):
    d1 = []
    d2 = []
    for row in dane:
        d1.append(row[0])
        d2.append(row[1])
    import pandas as pd
    d = {'temp': d1, 'class':d2}
    return pd.DataFrame(data=d)

# Uczenie sztucznei inteligencji
def learning(df, pomiar):
    from pyod.models.knn import KNN
    # Normalizacja danych uczących
    X = df['temp'].values.reshape(-1, 1)
    # Wyniki poprzenich pomiraów
    y = df['class'].values
    #
    clf = KNN(contamination=0.05, n_neighbors=5)
    clf.fit(X)
    clf.z
    y_train_pred = clf.labels_
    y_train_scores = clf.decision_scores_
    from pyod.utils import evaluate_print
    evaluate_print('KNN', y, y_train_scores)

    X_test = np.array([[pomiar]])
    print(clf.predict(X_test))
#Funkcja pobiera dane z pliku
def getDataFromFile():
    file = open('txt.txt', 'r')
    temp = float(file.read())
    file.close()
    return temp
db_hook = connect_db()
data = download_data(db_hook)
db_hook.close()
learning(prepare_data(data),getDataFromFile())






