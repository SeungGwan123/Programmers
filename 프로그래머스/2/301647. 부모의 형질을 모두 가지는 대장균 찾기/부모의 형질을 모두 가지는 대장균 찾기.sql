-- 코드를 작성해주세요
select a.ID as ID , a.GENOTYPE as GENOTYPE, b.GENOTYPE as PARENT_GENOTYPE 
from ecoli_data as a 
join ecoli_data b on a.parent_id = b.id
where a.genotype = (a.genotype | b.genotype)
order by id