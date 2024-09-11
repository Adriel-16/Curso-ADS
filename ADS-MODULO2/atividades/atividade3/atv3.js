let calcevent = document.getElementById("botao");
calcevent.addEventListener("click", calc);

function calc(){

    let valorA = parseFloat(document.getElementById("numero1").value);
    let valorB = parseFloat(document.getElementById("numero2").value);
    let valorC = parseFloat(document.getElementById("numero3").value);

    if(valorA > valorB && valorB > valorC){

        document.getElementById("coisas").innerHTML = "valor 1 é o maior";

    }
    
    else if(valorB > valorA && valorA > valorC){

        document.getElementById("coisas").innerHTML = "valor 2 é o maior";

    }else{

        document.getElementById("coisas").innerHTML = "valor 3 é o maior";

    }

    if(valorA < valorB && valorB < valorC){

        document.getElementById("coisas2").innerHTML = "valor 1 é o menor";

    }
    
    else if(valorB < valorA && valorA < valorC){

        document.getElementById("coisas2").innerHTML = "valor 2 é o menor";

    }else{

        document.getElementById("coisas2").innerHTML = "valor 3 é o menor";

    }

}