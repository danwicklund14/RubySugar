
Pod::Spec.new do |s|
  s.name         = "RubySugar"
  s.version      = "1.3.0"
  s.summary      = "Ports Ruby syntactic sugar to Objective-C."
  s.homepage     = "https://github.com/michalkonturek/RubySugar"
  s.license      = 'MIT'

  s.author       = { 
  "Michal Konturek" => "michal.konturek@gmail.com" 
  }

  s.ios.deployment_target = '7.0'

  s.social_media_url = 'https://twitter.com/michalkonturek'
  s.source       = { 
    :git => "https://github.com/michalkonturek/RubySugar.git", 
    :tag => s.version.to_s 
  }

  s.source_files = 'Source/**/*.{h,m}'
  s.requires_arc = true

  s.dependency 'MKFoundationKit/Block', '>= 1.2.0'
end