-- MySQL dump 10.13  Distrib 5.5.49, for debian-linux-gnu (x86_64)
--
-- Host: 0.0.0.0    Database: pset7
-- ------------------------------------------------------
-- Server version	5.5.49-0ubuntu0.14.04.1

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
-- Table structure for table `history`
--

DROP TABLE IF EXISTS `history`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `history` (
  `id` int(11) NOT NULL,
  `transaction` varchar(255) NOT NULL,
  `time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `symbol` varchar(255) NOT NULL,
  `shares` int(11) NOT NULL,
  `price` double NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `history`
--

LOCK TABLES `history` WRITE;
/*!40000 ALTER TABLE `history` DISABLE KEYS */;
INSERT INTO `history` VALUES (9,'','2016-11-27 13:55:19','TTT',50,32.15999984741211),(9,'SELL','2016-11-27 13:57:31','TTT',10,32.15999984741211),(9,'BUY','2016-11-27 14:59:26','MSFT',0,60.53),(9,'BUY','2016-11-27 15:00:04','TTT',0,32.16),(9,'BUY','2016-11-27 15:00:32','AAPL',0,111.79),(9,'SELL','2016-11-27 15:01:06','AAPL',5,111.79),(9,'SELL','2016-11-27 15:01:54','TTT',5,32.16),(20,'SELL','2016-11-27 15:04:33','TTT',5,32.16),(20,'SELL','2016-11-27 15:04:43','AAPL',5,111.79),(20,'BUY','2016-11-27 15:05:05','GOOG',0,761.68),(20,'SELL','2016-11-28 18:40:16','GOOG',5,772.6),(20,'BUY','2016-11-28 19:17:51','AAPL',0,111.83),(20,'BUY','2016-11-28 19:18:07','GOOG',0,773.27),(20,'SELL','2016-11-28 19:20:04','AAPL',50,111.85),(20,'SELL','2016-11-28 19:20:04','AAPL',0,111.85),(20,'SELL','2016-11-28 19:21:02','GOOG',150,773.115),(20,'BUY','2016-11-28 19:21:30','GOOG',0,773.1),(20,'BUY','2016-11-28 19:22:38','TTT',0,31.6),(20,'BUY','2016-11-28 19:23:57','WEB',0,16.4809),(9,'BUY','2016-11-28 19:45:58','GOOG',0,772.42),(9,'SELL','2016-11-28 19:51:15','MSFT',8,60.68),(9,'BUY','2016-11-28 19:51:28','MSFT',0,60.675),(9,'BUY','2016-11-28 19:53:36','TTT',10,31.52),(9,'SELL','2016-11-28 20:14:28','TTT',10,31.5617),(9,'BUY','2016-11-28 20:26:24','AAPL',50,111.81),(9,'BUY','2016-11-28 20:26:58','AAPL',100,111.7799),(9,'BUY','2016-11-28 20:27:41','GOOG',50,770.8369),(9,'BUY','2016-11-28 20:28:08','TTT',100,31.59),(9,'BUY','2016-11-28 20:32:14','WWW',10,24.68),(9,'BUY','2016-11-28 20:32:53','WEB',10,16.15),(9,'BUY','2016-11-28 20:34:27','WEB',3,16.1759),(9,'SELL','2016-11-28 20:34:51','AAPL',150,111.75),(9,'SELL','2016-11-28 20:34:58','MSFT',40,60.615),(9,'SELL','2016-11-28 20:35:09','GOOG',100,771.03),(9,'BUY','2016-11-28 21:09:43','GOOG',200,769.265),(9,'BUY','2016-11-28 21:12:15','TTT',1,31.47),(9,'BUY','2016-11-28 21:16:39','TTT',1,31.48),(9,'BUY','2016-11-28 21:18:51','TTT',1,31.48),(9,'BUY','2016-11-28 21:20:55','TTT',2,31.48),(9,'SELL','2016-11-28 21:25:54','GOOG',200,768.24),(9,'SELL','2016-11-28 21:26:02','TTT',105,31.43),(9,'SELL','2016-11-28 21:27:03','WEB',13,16.1),(9,'SELL','2016-11-28 21:27:09','WWW',10,24.64),(9,'BUY','2016-11-28 21:30:13','TTT',40,31.43),(9,'BUY','2016-11-28 21:30:27','GOOG',200,768.24),(9,'SELL','2016-11-28 21:32:33','GOOG',200,768.24),(9,'SELL','2016-11-28 21:33:12','TTT',40,31.43),(9,'BUY','2016-11-28 21:33:35','AAPL',333,111.57),(9,'BUY','2016-11-28 21:40:16','TTT',1,31.43),(9,'BUY','2016-11-29 19:03:44','TTT',5,31.2244),(9,'BUY','2016-11-29 19:05:12','TTT',10,31.2244),(9,'BUY','2016-11-29 19:05:32','TTT',1,31.2244),(9,'BUY','2016-11-29 19:09:54','TTT',1,31.2244),(9,'BUY','2016-11-29 19:20:44','TTT',1,31.16),(9,'SELL','2016-11-29 19:20:55','TTT',19,31.16),(9,'BUY','2016-11-29 19:22:09','GOOG',100,777.4766),(9,'BUY','2016-11-29 19:24:04','TTT',1,31.16),(9,'BUY','2016-11-29 19:30:20','TTT',1,31.16),(9,'BUY','2016-11-29 19:30:34','TTT',1,31.1),(9,'SELL','2016-11-29 19:52:46','AAPL',333,111.78),(9,'BUY','2016-11-29 19:53:06','TTT',5,31.19),(9,'SELL','2016-11-29 19:54:23','TTT',8,31.19),(9,'SELL','2016-11-29 19:54:33','GOOG',100,775.77),(9,'BUY','2016-11-30 20:10:43','TTT',10,32.2586),(9,'BUY','2016-12-03 05:20:01','GOOG',100,750.5),(9,'SELL','2016-12-03 18:15:26','TTT',10,32.91),(9,'BUY','2016-12-03 18:15:40','MSFT',50,59.25),(20,'SELL','2016-12-03 18:21:25','GOOG',150,750.5),(20,'BUY','2016-12-03 18:21:36','AAPL',50,109.9),(21,'BUY','2016-12-03 18:23:17','MSFT',20,59.25),(21,'BUY','2016-12-03 18:23:32','AAPL',20,109.9),(21,'BUY','2016-12-03 18:24:03','TTT',20,32.91),(21,'SELL','2016-12-03 18:24:27','MSFT',20,59.25),(22,'BUY','2016-12-03 20:41:03','MSFT',10,59.25),(22,'BUY','2016-12-03 20:41:15','GOOG',10,750.5),(22,'BUY','2016-12-03 20:41:31','AAPL',10,109.9),(22,'BUY','2016-12-03 20:41:52','TTT',20,32.91),(22,'SELL','2016-12-03 20:42:05','TTT',20,32.91),(22,'SELL','2016-12-03 20:42:15','MSFT',10,59.25);
/*!40000 ALTER TABLE `history` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `portfolio`
--

DROP TABLE IF EXISTS `portfolio`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `portfolio` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `symbol` varchar(255) NOT NULL,
  `shares` int(10) unsigned NOT NULL,
  PRIMARY KEY (`id`,`symbol`)
) ENGINE=InnoDB AUTO_INCREMENT=23 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `portfolio`
--

LOCK TABLES `portfolio` WRITE;
/*!40000 ALTER TABLE `portfolio` DISABLE KEYS */;
INSERT INTO `portfolio` VALUES (9,'goog',100),(9,'msft',50),(20,'aapl',50),(20,'msft',30),(20,'ttt',20),(20,'web',30),(21,'aapl',20),(21,'ttt',20),(22,'aapl',10),(22,'goog',10);
/*!40000 ALTER TABLE `portfolio` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `users`
--

DROP TABLE IF EXISTS `users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `users` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `cash` decimal(65,4) unsigned NOT NULL DEFAULT '0.0000',
  `username` varchar(255) NOT NULL,
  `hash` varchar(255) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `username` (`username`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `users`
--

LOCK TABLES `users` WRITE;
/*!40000 ALTER TABLE `users` DISABLE KEYS */;
INSERT INTO `users` VALUES (1,10000.0000,'andi','$2y$10$c.e4DK7pVyLT.stmHxgAleWq4yViMmkwKz3x8XCo4b/u3r8g5OTnS'),(2,10000.0000,'caesar','$2y$10$0p2dlmu6HnhzEMf9UaUIfuaQP7tFVDMxgFcVs0irhGqhOxt6hJFaa'),(3,10000.0000,'eli','$2y$10$COO6EnTVrCPCEddZyWeEJeH9qPCwPkCS0jJpusNiru.XpRN6Jf7HW'),(4,10000.0000,'hdan','$2y$10$o9a4ZoHqVkVHSno6j.k34.wC.qzgeQTBHiwa3rpnLq7j2PlPJHo1G'),(5,10000.0000,'jason','$2y$10$ci2zwcWLJmSSqyhCnHKUF.AjoysFMvlIb1w4zfmCS7/WaOrmBnLNe'),(6,10000.0000,'john','$2y$10$dy.LVhWgoxIQHAgfCStWietGdJCPjnNrxKNRs5twGcMrQvAPPIxSy'),(7,10000.0000,'levatich','$2y$10$fBfk7L/QFiplffZdo6etM.096pt4Oyz2imLSp5s8HUAykdLXaz6MK'),(8,10000.0000,'rob','$2y$10$3pRWcBbGdAdzdDiVVybKSeFq6C50g80zyPRAxcsh2t5UnwAkG.I.2'),(9,6651.9140,'skroob','$2y$10$395b7wODm.o2N7W5UZSXXuXwrC0OtFB17w4VjPnCIn/nvv9e4XUQK'),(10,10000.0000,'zamyla','$2y$10$UOaRF0LGOaeHG4oaEkfO4O7vfI34B1W23WqHr9zCpXL68hfQsS3/e'),(22,11066.9000,'acecode','$2y$10$TAohLQyOb.Zwc6Bm0tU/yusx1kDit7sk3w4kAVUikfDqMH7tVtZYq');
/*!40000 ALTER TABLE `users` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2016-12-03 20:43:14
