<!DOCTYPE html>
<html>
    <head>
        <title>Curso de C++ em Qt</title>
        <link rel="stylesheet" type="text/css" href="http://localhost/estilo.css">
    </head>
    <body>
        <h2>Usando pt_BR template</h2>
		<h3>{param} par&acirc;metro(s) recebido(s).</h3>
        <table>
            <tr><th colspan='2'>Dados Recebidos</th></tr>
            <tr><th>Nome</th><th>Valor</th></tr>
            {loop data}
            <tr>
                <td> {data.key}  </td>
                <td> {data.value}</td>
            </tr>
           {end data}
        </table>
    </body>
</html>
