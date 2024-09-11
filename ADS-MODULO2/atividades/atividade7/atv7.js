let multevent = document.getElementById("botao");
multevent.addEventListener("click", mult);

function mult(){

    let multi3 = 0;
    let multi5 = 0;

    for(i = 0; i < 1000; i++){

        if(i % 3 === 0){

            multi3 += i;

        }

        if(i % 5 === 0){

            multi5 += i;

        }

    }

    document.getElementById("par").innerHTML = "Somatórios dos Múltiplos de 3: " + multi3 + "<br>";
    document.getElementById("par2").innerHTML = "Somatórios dos Múltiplos de 5: " + multi5 + "<br>";
    document.getElementById("par3").innerHTML = "Somatórios dos Múltiplos de 5 e 3: " + parseInt(multi3 + multi5);
    

}