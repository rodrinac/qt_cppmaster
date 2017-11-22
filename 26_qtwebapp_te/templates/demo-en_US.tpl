<!DOCTYPE html>
<html>
    <head>
        <title>Curso de C++ em Qt</title>
        <link rel="stylesheet" type="text/css" href="http://localhost/estilo.css">
    </head>
    <body>
        <h2>Using en_US template</h2>
		<h3>{param} received parameter(s).</h3>
        <table>
            <tr><th colspan='2'>Received Data</th></tr>
            <tr><th>Name</th><th>Value</th></tr>
            {loop data}
            <tr>
                <td> {data.key}  </td>
                <td> {data.value}</td>
            </tr>
           {end data}
        </table>
    </body>
</html>
