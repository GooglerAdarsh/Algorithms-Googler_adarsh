Hii ,My name is ADARSH TIWARI & I am a student of IIIT ALLAHABAD currently pursuing B.Tech(IT)(III year) .my hometown is Sultanpur uttar pradesh. & the most importent thing is that in my Algorithms_Googler_adarsh Repositori each algo is made by my own concept.
IF u will finds bugs plz comment the bug & i will debug it.
thanks




/*what happens when you type in a URL in browser */
browser checks cache; if requested object is in cache and is fresh, skip to #9
browser asks OS for server's IP address
OS makes a DNS lookup and replies the IP address to the browser
browser opens a TCP connection to server (this step is much more complex with HTTPS)
browser sends the HTTP request through TCP connection
browser receives HTTP response and may close the TCP connection, or reuse it for another request
browser checks if the response is a redirect or a conditional response (3xx result status codes), authorization request (401), error (4xx and 5xx), etc.; these are handled differently from normal responses (2xx)
if cacheable, response is stored in cache
browser decodes response (e.g. if it's gzipped)
browser determines what to do with response (e.g. is it a HTML page, is it an image, is it a sound clip?)
browser renders response, or offers a download dialog for unrecognized types
