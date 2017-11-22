CREATE DATABASE `alunos`;
use alunos;

CREATE TABLE `dados`(
	`id` INT AUTO_INCREMENT,
	`nome` VARCHAR(45) NOT NULL,
	`nota` DOUBLE NOT NULL
);

INSERT INTO `dados` values
	(NULL, "João Matheus", 7.45),
	(NULL, "Ana Paula", 6),
	(NULL, "Jhonatan Silva", 9.6),
    (NULL, "Camila Magalhães", 4.5),
    (NULL, "Pedro Junior", 3.2);