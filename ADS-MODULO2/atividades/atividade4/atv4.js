let logevent1= document.getElementById("botao");
logevent1.addEventListener("click", login);

function login(){

    if(document.getElementById("idade").value >=18){
       
        document.getElementById("mostlog").innerHTML="você é de maior";

    }else{

        document.getElementById("mostlog").innerHTML="você é de menor";

    }
}