require 'uri'
require 'net/http'
require 'openssl'

blynk_api_token = "---YOUR_API_TOKEN---"
pin = "v5"

loop do
  time = Time.new
  current_date_time = time.strftime("%Y-%m-%d %Hh%Mm%Ss")
  url = URI("https://ny3.blynk.cloud/external/api/update?token=#{blynk_api_token}&#{pin}=#{current_date_time}")
  http = Net::HTTP.new(url.host, url.port)
  http.use_ssl = true
  http.verify_mode = OpenSSL::SSL::VERIFY_NONE

  puts "Setting pin #{pin} value: #{current_date_time}"
  request = Net::HTTP::Get.new(url)

  http.request(request)

  sleep 1
end
