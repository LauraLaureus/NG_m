global REAL coincidencias;

func inicio {
    VECTOR v = [16,35,66,16,5,9];
    REAL elementoBuscado = 16;
    REAL pos = 0;
    REAL coincidencias = 0;

    REAL d;

    mientras (pos < 6){
        d = v[pos];
        esCoincidencia(REAL d, REAL elementoBuscado);
        pos = pos + 1;
    }

}

func esCoincidencia(REAL e1, REAL e2){
    si (e1 == e2){
        coincidencias = coincidencias + 1;
    }

}