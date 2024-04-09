-- 코드를 작성해주세요
select count(1) as COUNT
from ecoli_data
where genotype & 2 !=2 and(genotype & 1 = 1 or genotype & 4 = 4)