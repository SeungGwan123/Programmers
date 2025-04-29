-- 코드를 작성해주세요
select year(a.differentiation_date) as YEAR, b.col_max - a.size_of_colony as YEAR_DEV, ID
from ecoli_data as a,
(select year(differentiation_date) as col_year, max(size_of_colony) as col_max from ecoli_data group by year(differentiation_date)) as b
where YEAR(a.differentiation_date) = b.col_year
order by year, YEAR_DEV;