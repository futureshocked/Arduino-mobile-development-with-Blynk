require 'uri'
require 'net/http'
require 'openssl'

blynk_api_token = "---YOUR_API_TOKEN---"
dataStreamId = 1

url = URI("https://ny3.blynk.cloud/external/api/get?token=#{blynk_api_token}&dataStreamId=#{dataStreamId}")

http = Net::HTTP.new(url.host, url.port)
http.use_ssl = true
http.verify_mode = OpenSSL::SSL::VERIFY_NONE

request = Net::HTTP::Get.new(url)

loop do
  response = http.request(request)
  puts "datastream ID #{dataStreamId} value: #{response.read_body}"
  sleep 1
end
