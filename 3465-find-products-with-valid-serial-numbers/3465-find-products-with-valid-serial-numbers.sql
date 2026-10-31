# Write your MySQL query statement below
-- //only 13 test pass out of 19
-- select * from products 
-- where description like '%SN____-____' or
-- description like '%SN____-____ %';

# Write your MySQL query statement below
# Write your MySQL query statement below
-- SELECT product_id, product_name, description
-- FROM Products
-- WHERE BINARY description REGEXP '\\bSN[0-9]{4}-[0-9]{4}\\b'
-- ORDER BY product_id ASC;
# Write your MySQL query statement below
SELECT product_id, product_name, description
FROM Products
WHERE REGEXP_LIKE(description, '\\bSN[0-9]{4}-[0-9]{4}\\b', 'c')
ORDER BY product_id ASC;