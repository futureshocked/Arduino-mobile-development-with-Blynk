require 'uri'
require 'net/http'
require 'openssl'

blynk_api_token = "---YOUR_API_TOKEN---"
pin = "v0"
value = 1

loop do
  value = if value == 1 then 0 else 1 end
  url = URI("https://ny3.blynk.cloud/external/api/update?token=#{blynk_api_token}&#{pin}=#{value}")
  http = Net::HTTP.new(url.host, url.port)
  http.use_ssl = true
  http.verify_mode = OpenSSL::SSL::VERIFY_NONE

  puts "Setting pin #{pin} value: #{value}"
  request = Net::HTTP::Get.new(url)

  http.request(request)

  sleep 1
end
