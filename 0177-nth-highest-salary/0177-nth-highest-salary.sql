-- //The main issue causing your runtime error is LIMIT N-1, 1.

-- In MySQL, you cannot perform mathematical operations like N - 1 directly inside the LIMIT clause. Furthermore, MySQL doesn't allow function parameters (N) directly inside LIMIT in a user-defined function without declaring a local variable first.

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    Declare M INT;
    set M=N-1;
  RETURN (
      # Write your MySQL query statement below.
    -- if count(distinct(salary))<N return null;
    select distinct(salary)  from employee
    order by salary desc
    LIMIT M,1
  );
END