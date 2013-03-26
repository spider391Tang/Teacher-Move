echo 'hello'

awk 'BEGIN{FS=","} {printf "%10s %10s %10s\n",$1, $2, $4}' test.csv > grep_info.csv
#http://das.doh.gov.tw/DAS/CityCode.ASP
sed -i -n '2,$p' grep_info.csv
sed -i 's/台北市/1/g' grep_info.csv
sed -i 's/台中市/3/g' grep_info.csv
sed -i 's/台南市/5/g' grep_info.csv
sed -i 's/高雄市/7/g' grep_info.csv
sed -i 's/基隆市/11/g' grep_info.csv
sed -i 's/新竹市/12/g' grep_info.csv
sed -i 's/嘉義市/22/g' grep_info.csv
sed -i 's/新北市/31/g' grep_info.csv
sed -i 's/桃園縣/32/g' grep_info.csv
sed -i 's/新竹縣/33/g' grep_info.csv
sed -i 's/宜蘭縣/34/g' grep_info.csv
sed -i 's/苗栗縣/35/g' grep_info.csv
sed -i 's/彰化縣/37/g' grep_info.csv
sed -i 's/南投縣/38/g' grep_info.csv
sed -i 's/雲林縣/39/g' grep_info.csv
sed -i 's/嘉義縣/40/g' grep_info.csv
sed -i 's/屏東縣/43/g' grep_info.csv
sed -i 's/澎湖縣/44/g' grep_info.csv
sed -i 's/花蓮縣/45/g' grep_info.csv
sed -i 's/臺東縣/46/g' grep_info.csv
sed -i 's/台東縣/46/g' grep_info.csv
sed -i 's/金門縣/90/g' grep_info.csv
sed -i 's/連江縣/91/g' grep_info.csv


