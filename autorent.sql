-- phpMyAdmin SQL Dump
-- version 4.7.4
-- https://www.phpmyadmin.net/
--
-- Хост: 127.0.0.1
-- Время создания: Июл 16 2019 г., 17:31
-- Версия сервера: 10.1.26-MariaDB
-- Версия PHP: 7.1.9

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- База данных: `autorent`
--

-- --------------------------------------------------------

--
-- Структура таблицы `auto`
--

CREATE TABLE `auto` (
  `id` int(10) UNSIGNED NOT NULL,
  `id_brand` int(20) UNSIGNED NOT NULL,
  `id_model` int(20) UNSIGNED NOT NULL,
  `color` varchar(15) NOT NULL,
  `year_start` year(4) NOT NULL,
  `auto_full` varchar(100) DEFAULT NULL,
  `VIN` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Дамп данных таблицы `auto`
--

INSERT INTO `auto` (`id`, `id_brand`, `id_model`, `color`, `year_start`, `auto_full`, `VIN`) VALUES
(1, 3, 1, 'Зеленый', 2012, 'Honda Accord (2012) (Зеленый) VIN: 9493', 'JF2SJABC8FH439493'),
(2, 5, 3, 'Зеленый', 2011, 'Hyundai i30 (2011) (Зеленый) VIN: 9678', '5FNRL5H62CB009678'),
(3, 4, 2, 'Коричневый', 2012, 'Kia Rio (2012) (Коричневый) VIN: 0036', '3C3EL55H9YT260036'),
(4, 4, 2, 'Фиолетовый', 2015, 'Kia Rio (2015) (Фиолетовый) VIN: 3277', '1GKKRSED0BJ213277'),
(9, 7, 8, 'Бордовый', 2015, 'Dodge Demon (2015) (Бордовый) VIN: 3241', 'JTLZE4FE3C1143241'),
(10, 6, 4, 'Желтый', 2015, 'Volkswagen Golf (2015) (Желтый) VIN: 2979', '5FNRL18623B002979'),
(11, 3, 1, 'Белый', 2006, 'Honda Accord (2006) (Белый) VIN: 2979', '5F3RL18623B002979');

-- --------------------------------------------------------

--
-- Структура таблицы `brand`
--

CREATE TABLE `brand` (
  `id` int(20) UNSIGNED NOT NULL,
  `brand_name` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Дамп данных таблицы `brand`
--

INSERT INTO `brand` (`id`, `brand_name`) VALUES
(1, 'Alfa Romeo'),
(2, 'Audi'),
(3, 'Honda'),
(4, 'Kia'),
(5, 'Hyundai'),
(6, 'Volkswagen'),
(7, 'Dodge'),
(8, 'Mercedes'),
(9, 'Nissan'),
(10, 'Renault'),
(11, 'Honda');

-- --------------------------------------------------------

--
-- Структура таблицы `client`
--

CREATE TABLE `client` (
  `id` int(15) UNSIGNED NOT NULL,
  `name` varchar(20) NOT NULL,
  `surname` varchar(20) NOT NULL,
  `patronymic` varchar(15) NOT NULL,
  `s_pass` int(5) UNSIGNED NOT NULL,
  `n_pass` int(7) UNSIGNED NOT NULL,
  `s_drive` int(5) UNSIGNED NOT NULL,
  `n_drive` int(7) UNSIGNED NOT NULL,
  `telephone` varchar(30) NOT NULL,
  `full_name` varchar(100) AS (CONCAT(name, " ", surname, " ", patronymic )) VIRTUAL,
  `pass_full` varchar(100) AS (CONCAT(s_pass, " ", n_pass)) VIRTUAL,
  `drive` varchar(100) AS (CONCAT(s_drive, " ", n_drive)) VIRTUAL,
  `search` varchar(200) AS (CONCAT(name, "  ", surname, " ", patronymic, " ", s_drive, " ", n_drive, " ", s_pass, " ", n_pass, " ", telephone)) VIRTUAL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Дамп данных таблицы `client`
--

INSERT INTO `client` (`id`, `name`, `surname`, `patronymic`, `s_pass`, `n_pass`, `s_drive`, `n_drive`, `telephone`, `full_name`, `pass_full`, `drive`, `search`) VALUES
(1, 'Игорь', 'Теплоков', 'Мечиславович', 4456, 286586, 4568, 456896, '8(910)591-03-85', 'Игорь Теплоков Мечиславович', '4456 286586', '4568 456896', 'Игорь  Теплоков Мечиславович 4568 456896 4456 286586 8(910)591-03-85'),
(2, 'Чеслав', 'Кедров', 'Агапович', 2685, 324689, 1235, 652368, '8(910)445-41-61', 'Чеслав Кедров Агапович', '2685 324689', '1235 652368', 'Чеслав  Кедров Агапович 1235 652368 2685 324689 8(910)445-41-61'),
(3, 'Светлана', 'Нечаева', 'Игоревна ', 5689, 652478, 4586, 652136, '8(910)018-52-23', 'Светлана Нечаева Игоревна ', '5689 652478', '4586 652136', 'Светлана  Нечаева Игоревна  4586 652136 5689 652478 8(910)018-52-23'),
(4, 'Анисья', 'Чебыкина', 'Леонидовна', 6546, 658983, 6526, 568796, '8(910)102-89-08', 'Анисья Чебыкина Леонидовна', '6546 658983', '6526 568796', 'Анисья  Чебыкина Леонидовна 6526 568796 6546 658983 8(910)102-89-08'),
(5, 'Оксана', 'Погребняка', 'Федоровна ', 6526, 652468, 5689, 875623, '8(910)941-24-24', 'Оксана Погребняка Федоровна ', '6526 652468', '5689 875623', 'Оксана  Погребняка Федоровна  5689 875623 6526 652468 8(910)941-24-24'),
(6, 'Дина', 'Северина', 'Ефимовна', 8563, 652468, 5689, 568746, '8(910)296-23-66', 'Дина Северина Ефимовна', '8563 652468', '5689 568746', 'Дина  Северина Ефимовна 5689 568746 8563 652468 8(910)296-23-66'),
(7, 'Ангелина', 'Рыбьякова', 'Романовна ', 5216, 589656, 4586, 652369, '8(910)481-53-39', 'Ангелина Рыбьякова Романовна ', '5216 589656', '4586 652369', 'Ангелина  Рыбьякова Романовна  4586 652369 5216 589656 8(910)481-53-39'),
(8, 'Розалия', 'Канкия', 'Марковна ', 5648, 652136, 6458, 658695, '8(910)388-70-93', 'Розалия Канкия Марковна ', '5648 652136', '6458 658695', 'Розалия  Канкия Марковна  6458 658695 5648 652136 8(910)388-70-93'),
(9, 'Аскольд', 'Диденков', 'Даниилович ', 8652, 652136, 4587, 658932, '8(910)792-65-71', 'Аскольд Диденков Даниилович ', '8652 652136', '4587 658932', 'Аскольд  Диденков Даниилович  4587 658932 8652 652136 8(910)792-65-71'),
(10, 'Александра', 'Ратникова', 'Ивановна ', 4456, 865246, 4571, 564896, '8(910)153-14-20', 'Александра Ратникова Ивановна ', '4456 865246', '4571 564896', 'Александра  Ратникова Ивановна  4571 564896 4456 865246 8(910)153-14-20');

-- --------------------------------------------------------

--
-- Структура таблицы `contract`
--

CREATE TABLE `contract` (
  `id` int(10) UNSIGNED NOT NULL,
  `id_client` int(10) UNSIGNED NOT NULL,
  `id_worker` int(10) UNSIGNED NOT NULL,
  `id_auto` int(20) UNSIGNED DEFAULT NULL,
  `cost` decimal(30,0) UNSIGNED NOT NULL,
  `start_contract` date NOT NULL,
  `end_contract` date NOT NULL,
  `status` varchar(100) AS (CONCAT(start_contract, " - ", end_contract)) VIRTUAL,
  `search` varchar(100) AS (CONCAT(start_contract, " - ", end_contract, " ", cost)) VIRTUAL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Дамп данных таблицы `contract`
--

INSERT INTO `contract` (`id`, `id_client`, `id_worker`, `id_auto`, `cost`, `start_contract`, `end_contract`, `status`, `search`) VALUES
(4, 2, 2, 4, '557', '2015-07-10', '2015-07-15', '2015-07-10 - 2015-07-15', '2015-07-10 - 2015-07-15 557'),
(5, 1, 3, 9, '1056', '2016-08-12', '2016-09-30', '2016-08-12 - 2016-09-30', '2016-08-12 - 2016-09-30 1056'),
(6, 1, 2, 1, '3056', '2016-04-20', '2016-05-25', '2016-04-20 - 2016-05-25', '2016-04-20 - 2016-05-25 3056'),
(7, 1, 1, 3, '4057', '2016-05-25', '2016-06-25', '2016-05-25 - 2016-06-25', '2016-05-25 - 2016-06-25 4057'),
(8, 9, 3, 10, '8656', '2016-03-25', '2016-05-15', '2016-03-25 - 2016-05-15', '2016-03-25 - 2016-05-15 8656'),
(9, 8, 2, 2, '8156', '2016-02-12', '2016-03-11', '2016-02-12 - 2016-03-11', '2016-02-12 - 2016-03-11 8156'),
(10, 6, 2, 4, '7667', '2015-07-11', '2016-01-01', '2015-07-11 - 2016-01-01', '2015-07-11 - 2016-01-01 7667');

-- --------------------------------------------------------

--
-- Структура таблицы `dtp`
--

CREATE TABLE `dtp` (
  `id` int(10) UNSIGNED NOT NULL,
  `id_auto_dtp` int(20) UNSIGNED DEFAULT NULL,
  `date_dtp` date NOT NULL,
  `place` varchar(15) NOT NULL,
  `total` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Дамп данных таблицы `dtp`
--

INSERT INTO `dtp` (`id`, `id_auto_dtp`, `date_dtp`, `place`, `total`) VALUES
(1, 1, '2000-01-01', 'пушкино', '2001-01-02'),
(199, 1, '2000-01-01', 'галкина', '2001-04-06'),
(200, 1, '2000-01-01', 'циолковского', '2001-06-09'),
(201, 1, '2000-01-01', 'галкина', '2001-09-02'),
(202, 1, '2000-01-01', 'циолковского', '2001-05-02'),
(203, 1, '2000-01-01', 'пушкино', '2001-10-02');

-- --------------------------------------------------------

--
-- Структура таблицы `inspect`
--

CREATE TABLE `inspect` (
  `id` int(10) UNSIGNED NOT NULL,
  `id_auto_inspect` int(20) UNSIGNED NOT NULL,
  `date_start` date NOT NULL,
  `date_end` date NOT NULL,
  `total` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Дамп данных таблицы `inspect`
--

INSERT INTO `inspect` (`id`, `id_auto_inspect`, `date_start`, `date_end`, `total`) VALUES
(1, 1, '2012-02-20', '2013-02-20', 'Пройдено'),
(2, 3, '2013-05-15', '2014-05-15', 'Пройдено');

-- --------------------------------------------------------

--
-- Структура таблицы `insurer`
--

CREATE TABLE `insurer` (
  `id` int(10) UNSIGNED NOT NULL,
  `id_auto_insurer` int(20) UNSIGNED NOT NULL,
  `name_ins` varchar(20) NOT NULL,
  `date_start` date NOT NULL,
  `date_end` date NOT NULL,
  `search` varchar(100) AS (CONCAT(date_start, "  ", date_end, " ", name_ins)) VIRTUAL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Дамп данных таблицы `insurer`
--

INSERT INTO `insurer` (`id`, `id_auto_insurer`, `name_ins`, `date_start`, `date_end`, `search`) VALUES
(1, 3, 'Сбербанк страхование', '2012-02-20', '2013-02-20', '2012-02-20  2013-02-20 Сбербанк страхование'),
(2, 1, 'РЕСО-Гарантия', '2014-05-15', '2015-05-15', '2014-05-15  2015-05-15 РЕСО-Гарантия');

-- --------------------------------------------------------

--
-- Структура таблицы `models`
--

CREATE TABLE `models` (
  `id` int(20) UNSIGNED NOT NULL,
  `model` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Дамп данных таблицы `models`
--

INSERT INTO `models` (`id`, `model`) VALUES
(1, 'Accord'),
(2, 'Rio'),
(3, 'i30'),
(4, 'Golf'),
(5, 'Logan'),
(6, 'Polo'),
(7, 'Jetta'),
(8, 'Demon'),
(9, 'Viper'),
(10, 'Tiguan');

-- --------------------------------------------------------

--
-- Структура таблицы `pts`
--

CREATE TABLE `pts` (
  `id` int(10) UNSIGNED NOT NULL,
  `id_auto_pts` int(10) UNSIGNED DEFAULT NULL,
  `serial` int(10) NOT NULL,
  `number` varchar(10) NOT NULL,
  `date` date NOT NULL,
  `search` varchar(100) AS (CONCAT(serial, " ", number, " ", date)) VIRTUAL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Дамп данных таблицы `pts`
--

INSERT INTO `pts` (`id`, `id_auto_pts`, `serial`, `number`, `date`, `search`) VALUES
(5, 1, 4456, 'ВА4534', '2012-02-17', '4456 ВА4534 2012-02-17'),
(6, 2, 4582, 'УВ3423', '2013-05-11', '4582 УВ3423 2013-05-11');

-- --------------------------------------------------------

--
-- Структура таблицы `reg`
--

CREATE TABLE `reg` (
  `id` int(10) UNSIGNED NOT NULL,
  `id_auto_reg` int(20) UNSIGNED DEFAULT NULL,
  `serial` int(5) UNSIGNED NOT NULL,
  `number` int(10) UNSIGNED NOT NULL,
  `date` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Дамп данных таблицы `reg`
--

INSERT INTO `reg` (`id`, `id_auto_reg`, `serial`, `number`, `date`) VALUES
(1, 1, 8564, 458626, '2012-02-20'),
(2, 4, 8962, 458526, '2013-05-15');

-- --------------------------------------------------------

--
-- Структура таблицы `worker`
--

CREATE TABLE `worker` (
  `id` int(10) UNSIGNED NOT NULL,
  `name` varchar(30) NOT NULL,
  `surname` varchar(30) NOT NULL,
  `patronymic` varchar(30) NOT NULL,
  `position` varchar(25) NOT NULL,
  `user_login` varchar(20) NOT NULL,
  `full_name` varchar(100) AS (CONCAT(name, " ", surname, " ", patronymic )) VIRTUAL,
  `search` varchar(200) AS (CONCAT(name, " ", surname, " ", patronymic, " ", position, " ", user_login)) VIRTUAL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Дамп данных таблицы `worker`
--

INSERT INTO `worker` (`id`, `name`, `surname`, `patronymic`, `position`, `user_login`, `full_name`, `search`) VALUES
(1, 'Максим', 'Уржумцев', 'Валерьянов', 'Менеджер', 'manager', 'Максим Уржумцев Валерьянов', 'Максим Уржумцев Валерьянов Менеджер manager'),
(2, 'Василий ', 'Зайцев ', 'Севастьянович', 'Начальник парка', 'admin', 'Василий  Зайцев  Севастьянович', 'Василий  Зайцев  Севастьянович Начальник парка admin'),
(3, 'Никита', 'Киреев', 'Михайлович', 'Менеджер', 'kireev', 'Никита Киреев Михайлович', 'Никита Киреев Михайлович Менеджер kireev');

--
-- Индексы сохранённых таблиц
--

--
-- Индексы таблицы `auto`
--
ALTER TABLE `auto`
  ADD PRIMARY KEY (`id`),
  ADD KEY `id` (`id`),
  ADD KEY `id_brand` (`id_brand`),
  ADD KEY `auto_ibfk_8` (`id_model`);

--
-- Индексы таблицы `brand`
--
ALTER TABLE `brand`
  ADD PRIMARY KEY (`id`);

--
-- Индексы таблицы `client`
--
ALTER TABLE `client`
  ADD PRIMARY KEY (`id`);

--
-- Индексы таблицы `contract`
--
ALTER TABLE `contract`
  ADD PRIMARY KEY (`id`),
  ADD KEY `id_client` (`id_client`),
  ADD KEY `id_worker` (`id_worker`),
  ADD KEY `contract_ibfk_3` (`id_auto`);

--
-- Индексы таблицы `dtp`
--
ALTER TABLE `dtp`
  ADD PRIMARY KEY (`id`),
  ADD KEY `dtp_ibfk_1` (`id_auto_dtp`);

--
-- Индексы таблицы `inspect`
--
ALTER TABLE `inspect`
  ADD PRIMARY KEY (`id`),
  ADD KEY `id_auto_inspect` (`id_auto_inspect`);

--
-- Индексы таблицы `insurer`
--
ALTER TABLE `insurer`
  ADD PRIMARY KEY (`id`),
  ADD KEY `id_auto_insurer` (`id_auto_insurer`);

--
-- Индексы таблицы `models`
--
ALTER TABLE `models`
  ADD PRIMARY KEY (`id`);

--
-- Индексы таблицы `pts`
--
ALTER TABLE `pts`
  ADD PRIMARY KEY (`id`),
  ADD KEY `id_auto_pts` (`id_auto_pts`);

--
-- Индексы таблицы `reg`
--
ALTER TABLE `reg`
  ADD PRIMARY KEY (`id`),
  ADD KEY `id_auto` (`id_auto_reg`);

--
-- Индексы таблицы `worker`
--
ALTER TABLE `worker`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT для сохранённых таблиц
--

--
-- AUTO_INCREMENT для таблицы `auto`
--
ALTER TABLE `auto`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=12;

--
-- AUTO_INCREMENT для таблицы `brand`
--
ALTER TABLE `brand`
  MODIFY `id` int(20) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=12;

--
-- AUTO_INCREMENT для таблицы `client`
--
ALTER TABLE `client`
  MODIFY `id` int(15) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT для таблицы `contract`
--
ALTER TABLE `contract`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT для таблицы `dtp`
--
ALTER TABLE `dtp`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=204;

--
-- AUTO_INCREMENT для таблицы `inspect`
--
ALTER TABLE `inspect`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT для таблицы `insurer`
--
ALTER TABLE `insurer`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT для таблицы `models`
--
ALTER TABLE `models`
  MODIFY `id` int(20) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT для таблицы `pts`
--
ALTER TABLE `pts`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- AUTO_INCREMENT для таблицы `reg`
--
ALTER TABLE `reg`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT для таблицы `worker`
--
ALTER TABLE `worker`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- Ограничения внешнего ключа сохраненных таблиц
--

--
-- Ограничения внешнего ключа таблицы `contract`
--
ALTER TABLE `contract`
  ADD CONSTRAINT `contract_ibfk_1` FOREIGN KEY (`id_client`) REFERENCES `client` (`id`) ON UPDATE CASCADE,
  ADD CONSTRAINT `contract_ibfk_2` FOREIGN KEY (`id_worker`) REFERENCES `worker` (`id`) ON UPDATE CASCADE,
  ADD CONSTRAINT `contract_ibfk_3` FOREIGN KEY (`id_auto`) REFERENCES `auto` (`id`) ON UPDATE CASCADE;

--
-- Ограничения внешнего ключа таблицы `dtp`
--
ALTER TABLE `dtp`
  ADD CONSTRAINT `dtp_ibfk_1` FOREIGN KEY (`id_auto_dtp`) REFERENCES `auto` (`id`) ON UPDATE CASCADE;

--
-- Ограничения внешнего ключа таблицы `inspect`
--
ALTER TABLE `inspect`
  ADD CONSTRAINT `inspect_ibfk_1` FOREIGN KEY (`id_auto_inspect`) REFERENCES `auto` (`id`);

--
-- Ограничения внешнего ключа таблицы `insurer`
--
ALTER TABLE `insurer`
  ADD CONSTRAINT `insurer_ibfk_1` FOREIGN KEY (`id_auto_insurer`) REFERENCES `auto` (`id`) ON UPDATE CASCADE;

--
-- Ограничения внешнего ключа таблицы `pts`
--
ALTER TABLE `pts`
  ADD CONSTRAINT `pts_ibfk_1` FOREIGN KEY (`id_auto_pts`) REFERENCES `auto` (`id`) ON UPDATE CASCADE;

--
-- Ограничения внешнего ключа таблицы `reg`
--
ALTER TABLE `reg`
  ADD CONSTRAINT `reg_ibfk_1` FOREIGN KEY (`id_auto_reg`) REFERENCES `auto` (`id`) ON UPDATE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
