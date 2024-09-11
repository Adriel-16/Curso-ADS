let imcevent = document.getElementById("btnimc");
imcevent.addEventListener("click", imc);

function imc(){

    let peso = document.getElementById("peso").value;
    let altura = document.getElementById("altura").value;

    let result =  parseFloat(peso) / (parseFloat(altura) * parseFloat(altura));
    document.getElementById("imcP").innerHTML = result;

}