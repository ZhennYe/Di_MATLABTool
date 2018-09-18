function varargout = adimat_diff_logm(varargin)
  ndd = size(varargin{1}, 1);
  nelx = numel(varargin{2});
  if ndd < nelx
    [partial varargout{2}] = partial_logm(varargin{2}, reshape(varargin{1}, [ndd, nelx]).');
    varargout{1} = reshape(partial.', [ndd size(varargin{2})]);
  else
    [partial varargout{2}] = partial_logm(varargin{2});
    varargout{1} = d_zeros(varargout{2});
    argsz = size(varargin{2});
    for d=1:ndd
      dd = varargin{1}(d,:);
      varargout{1}(d,:) = partial * dd(:);
    end 
  end
end
% automatically generated from $Id: derivatives-vdd.xml 3983 2013-12-21 11:20:23Z willkomm $
