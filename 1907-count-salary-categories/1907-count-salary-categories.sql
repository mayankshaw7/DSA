# Write your MySQL query statement below
select 'Low Salary' as category,count(income) as accounts_count from accounts 
where income<20000

UNION

select 'Average Salary' as category,count(income) as accounts_count from accounts 
where income between 20000 AND 50000

UNION
select 'High Salary' as category,count(income) as accounts_count from accounts 
where income>50000;