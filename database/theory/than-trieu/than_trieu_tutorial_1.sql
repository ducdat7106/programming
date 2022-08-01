# create database 
-- create database nguyen_van_hieu_exercise

# create table
-- create table than_trieu_tutorial.student(
-- 	id_student int,
--  name varchar(50),
--  address varchar(50),
--  email varchar(50),
--  avg float
-- );

#-------------------#------------alter table-------------#-------------------#-------------#
# add column into table
-- alter table than_trieu_tutorial.student
-- add first_name varchar(50), add sex varchar(10);

# delete column
-- alter table than_trieu_tutorial.student
-- drop first_name, drop sex ;

# modify name column, modify data type of column
-- alter table than_trieu_tutorial.student
-- modify column id_student int;

#----------------#---------------insert into-----------------#----------------------------#
# insert data into table
-- insert into than_trieu_tutorial.student
-- values (1, 'nguyen duc dat 1', 'khac niem 1 - bac ninh', 'nhiennhieny10@gmail.com', 5.0),
--         (2, 'nguyen duc dat 4', 'khac niem 6 - bac ninh', 'nhiennhieny101@gmail.com', 7.9),
--         (3, 'nguyen duc dat 10', 'khac niem 23 - bac ninh', 'nhiennhieny10345@gmail.com', 8.0), 
-- 	       (4, 'dang thi nhien 1', 'xuan hoi 2 bac ninh', 'nhiennhienn8@gmail.com', 9.4),
--        (5, 'nguyen thi nhung', 'nui chua bac ninh', 'nhiennhienn9@gmail.com', 9.1),
--        (6, 'lan anh', 'thuong bac ninh', 'nhiennhienn7@gmail.com', 9.8);

#---------------#--------#------detele-------------#------------#-------------------------#
#delete row
-- delete from than_trieu_tutorial.student
-- where id_student = 1;

#--------------#------------#-----select------------#------------#--------------------------#
# filter data on demand
-- select id_student, avg
-- from than_trieu_tutorial.student;

#--------------------------#----------------#----select distinct--------#-----------#-------------#
--  select distinct *
--  from than_trieu_tutorial.student

#-------------------------#-------------where---------------------#--------------------------------#
#filter records
-- select *
-- from than_trieu_tutorial.student
-- where id_student = 1; 


# find human have name tpye like '...d....'\
-- select *
-- from than_trieu_tutorial.student
-- where name like '%da%';


#---------------------------#---------------and, or, not   +  where-----------------#----------------------#


#---------------------------#--------------------order by----------------#--------------------------#

#-------------------#-------------------------#---update-----------------#-------------------------#
# mising where clause will update all tables sample one data same
-- update  than_trieu_tutorial.student
-- set id_student = 4
-- where  name = 'lan anh';

#------------------#--------------------sort data------------------#---------------#---------------#
-- select *
-- from than_trieu_tutorial.student
-- order by avg desc;

#------------------#-------------------#-------------#------get some record first---------------#


# display all data table
select * from than_trieu_tutorial.student;
