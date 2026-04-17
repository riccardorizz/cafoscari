# Problema del grattacielo

Un grattacielo ha `n` piani. Ogni piano può essere colorato di **bianco** o di **nero**, rispettando le seguenti regole:

* Non è possibile colorare **due piani consecutivi** entrambi di nero
* Ogni piano `i` offre una somma `v[i]` che viene incassata **solo se** il piano viene colorato di nero

L'obiettivo è scegliere la colorazione che **massimizza il guadagno totale**.

---

## Firma

```cpp
int grattacielo(const vector<int>& v, int piano, colore c);
```

dove colore è definito come:

```cpp
enum colore { bianco, nero };
```
## Parametri

* `v` — vettore delle offerte: `v[i]` rappresenta quanto paga il piano `i` se colorato di nero. In particolare, `v[0]` indica quanto paga il piano terra.
* `piano` — indice del **prossimo piano** di cui bisogna decidere il colore
* `c` — colore assegnato al **piano precedente** (`piano - 1`), necessario per verificare il vincolo sui piani consecutivi

---

## Obiettivo

Restituire il **guadagno massimo** ottenibile colorando i piani da `piano` fino all'ultimo (`n - 1`), sapendo che il piano precedente è stato colorato con il colore `c`.
