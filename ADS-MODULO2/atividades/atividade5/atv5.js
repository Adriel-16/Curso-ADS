let calcevent = document.getElementById("botao");
calcevent.addEventListener("click", media);

function media(){

    let num1 = document.getElementById("num1").value;
    let num2 = document.getElementById("num2").value;
    let num3 = document.getElementById("num3").value;

    let result = parseFloat(num1) + parseFloat(num2) + parseFloat(num3);
    result = result / 3;

    document.getElementById("para").innerHTML = result;

}