CREATE DATABASE `Empresa`;
use `Empresa`;

CREATE TABLE `departamento`(
	`ID` INT AUTO_INCREMENT,
    `Nome` VARCHAR(45),
    PRIMARY KEY(`ID`)
);

CREATE TABLE `funcionario`(
	`ID` INT AUTO_INCREMENT,
    `Nome` VARCHAR(45),
	`ID_Dep` INT NOT NULL,
    PRIMARY KEY(`ID`),
    FOREIGN KEY(`ID_Dep`) REFERENCES `departamento`(`ID`)
);

INSERT INTO `departamento` value(NULL, "Recursos Humanos");
INSERT INTO `departamento` value(NULL,          "Suporte");

INSERT INTO `funcionario` value(NULL,       "José Oliveira", 1);
INSERT INTO `funcionario` value(NULL,         "Allan Souza", 1);
INSERT INTO `funcionario` value(NULL,      "Kelly Cristina", 1);
INSERT INTO `funcionario` value(NULL,      "Estives D'óbes", 2);
INSERT INTO `funcionario` value(NULL,       "Willian Gates", 2);
INSERT INTO `funcionario` value(NULL, "Marque Zuquembergue", 1);


-- SELECT * FROM `funcionario`
-- SELECT * FROM `departamento`

/**
SELECT 
    `funcionario`.`ID`,
    `funcionario`.`Nome`,
    `departamento`.`Nome` AS `Departamento`
FROM
    `funcionario`
        INNER JOIN
    `departamento` ON `ID_Dep` = `departamento`.`ID`;
**/