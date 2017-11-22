CREATE DATABASE  IF NOT EXISTS `a3ltp2` /*!40100 DEFAULT CHARACTER SET utf8 COLLATE utf8_bin */;
USE `a3ltp2`;
-- MySQL dump 10.13  Distrib 5.7.9, for Win32 (AMD64)
--
-- Host: localhost    Database: a3ltp2
-- ------------------------------------------------------
-- Server version	5.5.5-10.1.10-MariaDB

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `carrinho`
--

DROP TABLE IF EXISTS `carrinho`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `carrinho` (
  `ID_produto` int(11) NOT NULL,
  UNIQUE KEY `ID_produto` (`ID_produto`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `carrinho`
--

LOCK TABLES `carrinho` WRITE;
/*!40000 ALTER TABLE `carrinho` DISABLE KEYS */;
INSERT INTO `carrinho` VALUES (1),(2),(3);
/*!40000 ALTER TABLE `carrinho` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `cliente`
--

DROP TABLE IF EXISTS `cliente`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `cliente` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `Nome` varchar(100) COLLATE utf8_bin NOT NULL,
  `Endereco` varchar(100) COLLATE utf8_bin DEFAULT NULL,
  `Telefone` varchar(20) COLLATE utf8_bin DEFAULT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB AUTO_INCREMENT=16 DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `cliente`
--

LOCK TABLES `cliente` WRITE;
/*!40000 ALTER TABLE `cliente` DISABLE KEYS */;
INSERT INTO `cliente` VALUES (1,'Luís Troxista','Macaé','5874587452'),(2,'João Ribeiro','Rua João Ferras nº 2','384541914'),(3,'José Rodrigo','QNM 7 casa 20','719426301'),(5,'Júlia Gomes','She lives in my heart','36587421545'),(6,'Allan Souzsa','801 Não sei das quantas','40028922'),(7,'Antoniêta','Lisboa 758','78954215698'),(8,'CEM 804 - Recanto das Emas','Quadra 804 Lote 1 - Área Especial','39013656'),(9,'Sociologia','Para jovens do século ','21'),(13,'Ceirista','78 gh 123 jh','1254879'),(14,'Larissa','Niterói','21145875647'),(15,'Fulano de tal','Taguatinga DF','9855441');
/*!40000 ALTER TABLE `cliente` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item_de_venda`
--

DROP TABLE IF EXISTS `item_de_venda`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item_de_venda` (
  `ID_Venda` int(11) DEFAULT NULL,
  `ID_Produto` int(11) DEFAULT NULL,
  `Quantidade` int(11) NOT NULL,
  KEY `idv_fk_1` (`ID_Venda`),
  KEY `idv_fk_2` (`ID_Produto`),
  CONSTRAINT `idv_fk_1` FOREIGN KEY (`ID_Venda`) REFERENCES `venda` (`ID`),
  CONSTRAINT `idv_fk_2` FOREIGN KEY (`ID_Produto`) REFERENCES `produto` (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `item_de_venda`
--

LOCK TABLES `item_de_venda` WRITE;
/*!40000 ALTER TABLE `item_de_venda` DISABLE KEYS */;
INSERT INTO `item_de_venda` VALUES (3,1,9),(11,2,2),(11,6,13),(12,6,2),(13,1,2),(14,5,1),(15,6,2),(16,6,4),(17,4,8722),(18,4,145),(19,4,145),(20,4,9855),(21,2,1),(22,2,1),(23,2,1),(23,4,770),(24,4,439),(24,5,1),(25,4,561),(25,1,1),(26,3,1),(26,4,86),(27,4,914),(28,4,552),(29,2,1),(29,1,45),(30,4,448),(31,4,400),(32,4,600),(32,6,2);
/*!40000 ALTER TABLE `item_de_venda` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `produto`
--

DROP TABLE IF EXISTS `produto`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `produto` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `Descricao` varchar(25) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `Valor` double NOT NULL,
  `Quantidade` int(11) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=ucs2 COLLATE=ucs2_bin;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `produto`
--

LOCK TABLES `produto` WRITE;
/*!40000 ALTER TABLE `produto` DISABLE KEYS */;
INSERT INTO `produto` VALUES (1,'Fio metalico',4.5,4501),(2,'Madeirite',4.25,1),(3,'Correntes',0.75,1),(4,'Telhas',1.95,1435000),(5,'Havaianas',7.56,2),(6,'C++ How to Program 10th',79.5,18),(7,'Relogio de parede',74.3,20);
/*!40000 ALTER TABLE `produto` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `venda`
--

DROP TABLE IF EXISTS `venda`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `venda` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `ID_Cliente` int(11) NOT NULL,
  `ID_Vendedor` int(11) NOT NULL,
  PRIMARY KEY (`ID`),
  KEY `venda_fk_1` (`ID_Cliente`),
  KEY `venda_fk_2` (`ID_Vendedor`),
  CONSTRAINT `venda_fk_1` FOREIGN KEY (`ID_Cliente`) REFERENCES `cliente` (`ID`),
  CONSTRAINT `venda_fk_2` FOREIGN KEY (`ID_Vendedor`) REFERENCES `vendedor` (`ID`)
) ENGINE=InnoDB AUTO_INCREMENT=33 DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `venda`
--

LOCK TABLES `venda` WRITE;
/*!40000 ALTER TABLE `venda` DISABLE KEYS */;
INSERT INTO `venda` VALUES (3,2,1),(11,2,1),(12,8,2),(13,6,1),(14,5,1),(15,3,1),(16,7,1),(17,9,1),(18,6,2),(19,3,2),(20,5,2),(21,7,1),(22,2,1),(23,1,2),(24,2,2),(25,6,2),(26,1,2),(27,5,1),(28,5,1),(29,7,3),(30,5,5),(31,13,1),(32,5,5);
/*!40000 ALTER TABLE `venda` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `vendedor`
--

DROP TABLE IF EXISTS `vendedor`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `vendedor` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `Nome` varchar(100) COLLATE utf8_bin NOT NULL,
  `Login` varchar(25) COLLATE utf8_bin NOT NULL,
  `Senha` varchar(25) COLLATE utf8_bin NOT NULL,
  PRIMARY KEY (`ID`),
  UNIQUE KEY `Login` (`Login`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `vendedor`
--

LOCK TABLES `vendedor` WRITE;
/*!40000 ALTER TABLE `vendedor` DISABLE KEYS */;
INSERT INTO `vendedor` VALUES (1,'Administrador Geral','Admin','1234'),(2,'Convidado','user123','user123'),(3,'Troxista','3214','3214'),(5,'Andzzz','Anders','1234');
/*!40000 ALTER TABLE `vendedor` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2017-01-16  7:24:36
