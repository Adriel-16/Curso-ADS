function gerarTabelaNumerosPrimos() {
    var tabelaHTML = "<table><tr><th colspan='50'>Números Primos entre 0 e 200</th></tr><tr><td>1";
    var primosEncontrados = 0;
  
    for (var dividendo = 2; dividendo <= 200; dividendo++) {
      var ehPrimo = true;
      for (var divisor = 2; divisor < dividendo; divisor++) {
        if (dividendo % divisor == 0) {
          ehPrimo = false;
          tabelaHTML += "<td>" + dividendo;
          break;
        }
      }
  
      if (ehPrimo) { 
        tabelaHTML += "<td bgcolor='#bc57ff'>" + dividendo;
        primosEncontrados++;
      }
  
      if (dividendo % 20 == 0) {
        tabelaHTML += "</tr><tr>";
      }
    }
  
    tabelaHTML += "</tr></table>";
  
    return tabelaHTML;
  }
  
  // Função para inserir a tabela gerada no documento
  function inserirTabelaNoDocumento() {
    var divTabela = document.getElementById('tabelaPrimos');
    divTabela.innerHTML = gerarTabelaNumerosPrimos();
  
    // Mostrar o número de primos encontrados
    var primosEncontrados = document.querySelectorAll('#tabelaPrimos td[bgcolor="#bc57ff"]').length;
    divTabela.innerHTML += 'Primos encontrados: ' + primosEncontrados + '<br>';
  }
  
  // Chamando a função para inserir a tabela quando o documento estiver pronto
  document.addEventListener('DOMContentLoaded', function() {
    inserirTabelaNoDocumento();
  });
  